#pragma once
#include <string>

/// <summary>
/// Структура адреса светофора
/// </summary>
struct Address
{
    std::string country;   // Страна
    std::string city;      // Город
    std::string street;    // Улица
    double latitude;       // Широта
    double longitude;      // Долгота
};