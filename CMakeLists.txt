cmake_minimum_required(VERSION 3.20)
project(UartCoSimulation VERSION 1.0 LANGUAGES CXX)

# Require C++17 for modern features (std::unique_ptr, string_view)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Find Verilator on the host system
find_package(verilator REQUIRED)

# 2. Define our hardware source files
set(VERILOG_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/hw/uart.sv
)

# 3. Instruct Verilator to transpile the SystemVerilog into a C++ library
# The 'TRACE' flag allows us to output .vcd waveform files for debugging later
verilate(simulated_hardware
    SOURCES ${VERILOG_SOURCES}
    TRACE
    PREFIX Vuart
)

# 4. Define our C++ software testbench
set(CXX_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UartDriver.cpp
)

# 5. Create the final executable
add_executable(uart_sim ${CXX_SOURCES})

# Include our header directories
target_include_directories(uart_sim PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 6. Link the transpiled Verilog C++ model to our handwritten C++ testbench
target_link_libraries(uart_sim PRIVATE simulated_hardware)