# Verilated -*- CMake -*-
# DESCRIPTION: Verilator output: CMake include script with class lists
#
# This CMake script lists generated Verilated files, for including in higher level CMake scripts.
# This file is meant to be consumed by the verilate() function,
# which becomes available after executing `find_package(verilator).

### Constants...
set(PERL "perl" CACHE FILEPATH "Perl executable (from $PERL, defaults to 'perl' if not set)")
set(PYTHON3 "python3" CACHE FILEPATH "Python3 executable (from $PYTHON3, defaults to 'python3' if not set)")
set(VERILATOR_ROOT "/usr/share/verilator" CACHE PATH "Path to Verilator kit (from $VERILATOR_ROOT)")
set(VERILATOR_SOLVER "" CACHE STRING "Default SMT solver for constrained randomization (from $VERILATOR_SOLVER)")

### Compiler flags...
# User CFLAGS (from -CFLAGS on Verilator command line)
set(Vuart_USER_CFLAGS )
# User LDLIBS (from -LDFLAGS on Verilator command line)
set(Vuart_USER_LDLIBS )

### Switches...
# SystemC output mode?  0/1 (from --sc)
set(Vuart_SC 0)
# Coverage output mode?  0/1 (from --coverage)
set(Vuart_COVERAGE 0)
# Timing mode?  0/1
set(Vuart_TIMING 0)
# Threaded output mode?  1/N threads (from --threads)
set(Vuart_THREADS 1)
# VCD Tracing output mode?  0/1 (from --trace)
set(Vuart_TRACE_VCD 1)
# FST Tracing output mode? 0/1 (from --trace-fst)
set(Vuart_TRACE_FST 0)

### Sources...
# Global classes, need linked once per executable
set(Vuart_GLOBAL "${VERILATOR_ROOT}/include/verilated.cpp" "${VERILATOR_ROOT}/include/verilated_vcd_c.cpp" "${VERILATOR_ROOT}/include/verilated_threads.cpp" )
# Generated module classes, non-fast-path, compile with low/medium optimization
set(Vuart_CLASSES_SLOW "/home/zach/Github/HAL/build/CMakeFiles/uart_sim.dir/Vuart.dir/Vuart___024root__Slow.cpp" "/home/zach/Github/HAL/build/CMakeFiles/uart_sim.dir/Vuart.dir/Vuart___024root__DepSet_ha21bd04d__0__Slow.cpp" )
# Generated module classes, fast-path, compile with highest optimization
set(Vuart_CLASSES_FAST "/home/zach/Github/HAL/build/CMakeFiles/uart_sim.dir/Vuart.dir/Vuart.cpp" "/home/zach/Github/HAL/build/CMakeFiles/uart_sim.dir/Vuart.dir/Vuart___024root__DepSet_hd9b01d36__0.cpp" "/home/zach/Github/HAL/build/CMakeFiles/uart_sim.dir/Vuart.dir/Vuart___024root__DepSet_ha21bd04d__0.cpp" )
# Generated support classes, non-fast-path, compile with low/medium optimization
set(Vuart_SUPPORT_SLOW "/home/zach/Github/HAL/build/CMakeFiles/uart_sim.dir/Vuart.dir/Vuart__Syms.cpp" "/home/zach/Github/HAL/build/CMakeFiles/uart_sim.dir/Vuart.dir/Vuart__Trace__0__Slow.cpp" "/home/zach/Github/HAL/build/CMakeFiles/uart_sim.dir/Vuart.dir/Vuart__TraceDecls__0__Slow.cpp" )
# Generated support classes, fast-path, compile with highest optimization
set(Vuart_SUPPORT_FAST "/home/zach/Github/HAL/build/CMakeFiles/uart_sim.dir/Vuart.dir/Vuart__Trace__0.cpp" )
# All dependencies
set(Vuart_DEPS "/home/zach/Github/HAL/hw/uart.sv" "/usr/share/verilator/include/verilated_std.sv" "/usr/share/verilator/include/verilated_std_waiver.vlt" )
# User .cpp files (from .cpp's on Verilator command line)
set(Vuart_USER_CLASSES )
