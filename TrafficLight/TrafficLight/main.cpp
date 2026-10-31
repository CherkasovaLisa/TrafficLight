#include <iostream>
#include <chrono>
#include <thread>
#include "TrafficLight.h"
#include <clocale>

using namespace std::chrono_literals;

int main()
{
    std::setlocale(LC_ALL, "ru_RU.UTF-8"); // или "" для системной локали
    
    // Тестовый светофор: Москва, Тверская улица
    Address addr{ "Россия", "Мытищи", "улица Борисовка", 55.921130, 37.710911 };

    // Отладка — проверяем, что строки дошли
    std::cout << "DEBUG country: [" << addr.country << "]\n";
    std::cout << "DEBUG city:    [" << addr.city << "]\n";
    std::cout << "DEBUG street:  [" << addr.street << "]\n";

    TrafficLight light(addr);

    while (true)
    {
        light.GetInfo();
        std::this_thread::sleep_for(23000ms);
    }

    return 0;
}