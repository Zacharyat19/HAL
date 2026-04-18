#include <iostream>

#include "../Inc/UartDriver.h"

int main() {
    std::cout << "Starting Verilator Co-simulation..." << std::endl;

    // Instantiate the driver. This automatically allocates the Verilog model 
    // and calls the reset() function we defined.
    UartDriver driver;
    
    std::cout << "Hardware model initialized and reset." << std::endl;

    // Run a few simulated clock cycles to ensure the evaluation loop doesn't crash
    driver.tickClock(10);

    // According to the UART protocol, the TX line should idle HIGH (1)
    if (driver.readTxPin()) 
    {
        std::cout << "SUCCESS: Verilog TX pin is idling HIGH as expected." << std::endl;
    } else 
    {
        std::cout << "FAILURE: Verilog TX pin is incorrectly idling LOW." << std::endl;
        return 1;
    }

    std::cout << "All systems nominal. Exiting." << std::endl;
    return 0;
}