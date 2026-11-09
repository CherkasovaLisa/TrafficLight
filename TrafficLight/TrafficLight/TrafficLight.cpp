#include "TrafficLight.h"
#include <iostream>
#include <chrono>
#include <iomanip>

TrafficLight::TrafficLight(const Address& addr, int off) : address(addr), offset(off) {}

TrafficLightsState TrafficLight::GetCurrentState() const
{
    auto now = std::chrono::system_clock::now();
    auto now_sec = std::chrono::floor<std::chrono::seconds>(now).time_since_epoch();

    // Безопасно приводим время к int (long long -> int)
    long long total_seconds = now_sec.count();
    int seconds = static_cast<int>((total_seconds + offset) % 60);

    if (seconds < 0) seconds += 60; // Защита от отрицательного времени

    if (seconds >= 0 && seconds <= 5)
        return TrafficLightsState::RED;
    else if (seconds >= 6 && seconds <= 35)
        return TrafficLightsState::YELLOW;
    else if (seconds >= 36 && seconds <= 41)
        return TrafficLightsState::GREEN;
    else
        return TrafficLightsState::YELLOW;
}

std::string TrafficLight::StateToString(TrafficLightsState state)
{
    switch (state)
    {
    case TrafficLightsState::RED:    return "RED";
    case TrafficLightsState::YELLOW: return "YELLOW";
    case TrafficLightsState::GREEN:  return "GREEN";
    }
    return "UNKNOWN";
}

std::string TrafficLight::ColorCode(TrafficLightsState state)
{
    switch (state)
    {
    case TrafficLightsState::RED:    return "\033[1;31m";
    case TrafficLightsState::YELLOW: return "\033[1;33m";
    case TrafficLightsState::GREEN:  return "\033[1;32m";
    }
    return "\033[0m";
}

void TrafficLight::GetInfo() const
{
    TrafficLightsState state = GetCurrentState();
    std::string color = ColorCode(state);

    std::cout << "============================================\n";
    std::cout << "   ИНФОРМАЦИЯ О СВЕТОФОРЕ\n";
    std::cout << "============================================\n";
    std::cout << " Страна:      " << address.country << "\n";
    std::cout << " Город:       " << address.city << "\n";
    std::cout << " Улица:       " << address.street << "\n";
    std::cout << " Координаты:  " << std::fixed << std::setprecision(6)
        << address.latitude << ", " << address.longitude << "\n";
    std::cout << "--------------------------------------------\n";
    std::cout << " Текущий свет: " << color
        << StateToString(state) << "\033[0m\n";
    std::cout << "============================================\n\n";
}