#pragma once
#include <string>
#include <nlohmann/json.hpp> // Подключаем библиотеку

using string = std::string;
using json = nlohmann::json;

/// <summary>
/// Структура адреса светофора
/// </summary>
struct Address
{
    string country;   // Страна
    string city;      // Город
    string street;    // Улица
    double latitude;       // Широта
    double longitude;      // Долгота
};
 
void to_json(json& j, const Address& addr)
{
    j = json
    {
        { "country", addr.country },
        { "city", addr.city },
        { "street", addr.street },
        { "latitude", addr.latitude},
        { "longitude", addr.longitude}
    };
}

void from_json(const json& j, Address& addr)
{
    j.at("country").get_to(addr.country);
    j.at("city").get_to(addr.city);
    j.at("street").get_to(addr.street);
    j.at("latitude").get_to(addr.latitude);
    j.at("longitude").get_to(addr.longitude);
};