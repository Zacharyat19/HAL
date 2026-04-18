#pragma once
#include <memory>
#include <cstdint>

// Forward declare the Verilator-generated class to keep compile times fast
class Vuart;

class UartDriver 
{
    public:
        UartDriver();
        ~UartDriver();

        // Hardware cannot be copied
        UartDriver(const UartDriver&) = delete;
        UartDriver& operator=(const UartDriver&) = delete;

        // Hardware interactions
        void reset();
        void tickClock(uint64_t cycles = 1);
        
        // Pin interactions
        void setRxPin(bool state);
        bool readTxPin() const;

    private:
        std::unique_ptr<Vuart> m_core;
        uint64_t m_time; // Tracks simulated time
};