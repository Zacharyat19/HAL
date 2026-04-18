// hw/uart.sv
`timescale 1ns / 1ps

module uart #(
    // In simulation, we want a low clock-to-bit ratio so the tests run instantly 
    // and the waveform files stay small. We default to 8 clocks per bit.
    parameter CLOCKS_PER_BIT = 8 
) (
    input  logic       clk,
    input  logic       rst,

    // TX Interface (C++ to Verilog)
    input  logic [7:0] tx_data,
    input  logic       tx_en,
    output logic       tx_ready,
    output logic       tx,

    // RX Interface (Verilog to C++)
    input  logic       rx,
    output logic [7:0] rx_data,
    output logic       rx_valid
);

    // ==========================================
    // Transmitter (TX) State Machine
    // ==========================================
    typedef enum logic [2:0] {
        TX_IDLE,
        TX_START,
        TX_DATA,
        TX_STOP
    } tx_state_t;

    tx_state_t tx_state;
    logic [7:0] tx_shift_reg;
    logic [2:0] tx_bit_idx;
    integer tx_clk_count;

    always_ff @(posedge clk) begin
        if (rst) begin
            tx_state <= TX_IDLE;
            tx <= 1'b1; // Line idles high
            tx_ready <= 1'b1;
            tx_clk_count <= 0;
            tx_bit_idx <= 0;
        end else begin
            case (tx_state)
                TX_IDLE: begin
                    tx <= 1'b1;
                    tx_ready <= 1'b1;
                    if (tx_en) begin
                        tx_shift_reg <= tx_data;
                        tx_state <= TX_START;
                        tx_ready <= 1'b0;
                        tx_clk_count <= 0;
                    end
                end
                TX_START: begin
                    tx <= 1'b0; // Pull low for start bit
                    if (tx_clk_count < CLOCKS_PER_BIT - 1) begin
                        tx_clk_count <= tx_clk_count + 1;
                    end else begin
                        tx_clk_count <= 0;
                        tx_state <= TX_DATA;
                        tx_bit_idx <= 0;
                    end
                end
                TX_DATA: begin
                    tx <= tx_shift_reg[tx_bit_idx]; // Shift data out LSB first
                    if (tx_clk_count < CLOCKS_PER_BIT - 1) begin
                        tx_clk_count <= tx_clk_count + 1;
                    end else begin
                        tx_clk_count <= 0;
                        if (tx_bit_idx < 7) begin
                            tx_bit_idx <= tx_bit_idx + 1;
                        end else begin
                            tx_state <= TX_STOP;
                        end
                    end
                end
                TX_STOP: begin
                    tx <= 1'b1; // Pull high for stop bit
                    if (tx_clk_count < CLOCKS_PER_BIT - 1) begin
                        tx_clk_count <= tx_clk_count + 1;
                    end else begin
                        tx_state <= TX_IDLE;
                        tx_ready <= 1'b1;
                    end
                end
                default: tx_state <= TX_IDLE;
            endcase
        end
    end

    // ==========================================
    // Receiver (RX) State Machine
    // ==========================================
    typedef enum logic [2:0] {
        RX_IDLE,
        RX_START,
        RX_DATA,
        RX_STOP
    } rx_state_t;

    rx_state_t rx_state;
    logic [2:0] rx_bit_idx;
    integer rx_clk_count;

    always_ff @(posedge clk) begin
        if (rst) begin
            rx_state <= RX_IDLE;
            rx_valid <= 1'b0;
            rx_data <= 8'h00;
            rx_clk_count <= 0;
            rx_bit_idx <= 0;
        end else begin
            // Clear the valid pulse after one cycle
            if (rx_valid) rx_valid <= 1'b0;

            case (rx_state)
                RX_IDLE: begin
                    if (rx == 1'b0) begin // Detect dropping start bit
                        rx_state <= RX_START;
                        rx_clk_count <= 0;
                    end
                end
                RX_START: begin
                    // Wait until the middle of the start bit to sample
                    if (rx_clk_count < (CLOCKS_PER_BIT / 2) - 1) begin
                        rx_clk_count <= rx_clk_count + 1;
                    end else begin
                        if (rx == 1'b0) begin // Confirm it wasn't a noise spike
                            rx_clk_count <= 0;
                            rx_state <= RX_DATA;
                            rx_bit_idx <= 0;
                        end else begin
                            rx_state <= RX_IDLE; 
                        end
                    end
                end
                RX_DATA: begin
                    // Wait one full bit duration to sample the middle of the next bit
                    if (rx_clk_count < CLOCKS_PER_BIT - 1) begin
                        rx_clk_count <= rx_clk_count + 1;
                    end else begin
                        rx_clk_count <= 0;
                        rx_data[rx_bit_idx] <= rx; // Read the pin state
                        if (rx_bit_idx < 7) begin
                            rx_bit_idx <= rx_bit_idx + 1;
                        end else begin
                            rx_state <= RX_STOP;
                        end
                    end
                end
                RX_STOP: begin
                    if (rx_clk_count < CLOCKS_PER_BIT - 1) begin
                        rx_clk_count <= rx_clk_count + 1;
                    end else begin
                        rx_state <= RX_IDLE;
                        if (rx == 1'b1) begin // Confirm stop bit is high
                            rx_valid <= 1'b1;
                        end
                    end
                end
                default: rx_state <= RX_IDLE;
            endcase
        end
    end

endmodule