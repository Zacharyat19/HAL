cmake_minimum_required(VERSION 3.20)
project(UartCoSimulation VERSION 1.0 LANGUAGES CXX)

cmake_policy(SET CMP0144 NEW)

# Require C++17 for modern features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Find Verilator on the host system
find_package(verilator REQUIRED)

# 2. Define our source files
set(VERILOG_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/hw/uart.sv
)

set(CXX_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/UartDriver.cpp
)

# 3. Create the executable target FIRST
add_executable(uart_sim ${CXX_SOURCES})

# 4. Instruct Verilator to transpile the SystemVerilog and attach it to our executable
verilate(uart_sim
    SOURCES ${VERILOG_SOURCES}
    TRACE
    PREFIX Vuart
)

# 5. Include our header directories AND the generated Verilator headers
target_include_directories(uart_sim PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Inc 
    ${CMAKE_CURRENT_BINARY_DIR}
)