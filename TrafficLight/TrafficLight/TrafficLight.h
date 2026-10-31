#pragma once
#include <string>
#include "Address.h"
#include "TrafficLightsState.h"

class TrafficLight
{
private:
    Address address;

public:
    TrafficLight(const Address& addr);

    TrafficLightsState GetCurrentState() const;
    void GetInfo() const;

    static std::string StateToString(TrafficLightsState state);
    static std::string ColorCode(TrafficLightsState state);
};