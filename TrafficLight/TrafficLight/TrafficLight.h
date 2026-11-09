#pragma once
#include <string>
#include "Address.h"
#include "TrafficLightsState.h"

class TrafficLight
{
private:
    Address address;
    int offset;

public:
    TrafficLight() : offset(0) {} // <--- ЭТА СТРОКА ОБЯЗАТЕЛЬНА
    TrafficLight(const Address& addr, int off);

    TrafficLightsState GetCurrentState() const;
    void GetInfo() const;

    static std::string StateToString(TrafficLightsState state);
    static std::string ColorCode(TrafficLightsState state);
};