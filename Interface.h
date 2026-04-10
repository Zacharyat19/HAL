#include <string>
#include <memory>
#include <iostream>

// The Interface
class IHardwareNode 
{
public:
    virtual ~IHardwareNode() = default;

    virtual bool initialize() = 0;
    virtual std::string readTelemetry() = 0;
    virtual bool sendCommand(const std::string& command) = 0;
};