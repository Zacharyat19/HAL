# UART Co-Simulation & Hardware-in-the-Loop (HIL) Framework

## Overview
This project implements a high-performance hardware-software co-simulation environment for a SystemVerilog UART core. By leveraging Verilator, the RTL logic is transpiled into a modern C++ class, allowing for deterministic software-driven verification without the need for physical hardware. 

This repository serves as a practical implementation of Hardware-in-the-Loop (HIL) concepts, demonstrating how to bridge the gap between RTL design and high-level systems programming in C++.

## Technical Architecture
The system is divided into three primary layers:
1.  **Hardware Layer (RTL):** A robust SystemVerilog UART module implementing an oversampling receiver and a state-machine-driven transmitter.
2.  **Simulation Layer (Verilator):** An industry-standard transpiler that converts the SystemVerilog logic into high-efficiency C++ models.
3.  **Driver Layer (C++17):** A custom Hardware Abstraction Layer (HAL) using the RAII pattern to manage the lifecycle of the simulated hardware and provide a clean interface for system-level interactions.

## Key Features
- **Deterministic Co-simulation:** Tick-accurate simulation of hardware clock cycles within a standard C++ runtime.
- **Modern C++ Design:** Utilizes `std::unique_ptr` for memory safety and forward declarations to minimize compilation times and maximize encapsulation.
- **ARM64 Optimized:** Specifically designed and tested on the Raspberry Pi 5 (Silicon Forest environment) for native performance.
- **Fault-Tolerant RTL:** The UART core includes exhaustive case coverage and default state resets, adhering to industry best practices for safety-critical systems.
