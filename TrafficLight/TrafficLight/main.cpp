#include <fstream>
#include <iostream>
#include <chrono>
#include <thread>
#include "TrafficLight.h"

using namespace std;
using json = nlohmann::json;

TrafficLight loadLight(string filename)
{
    ifstream file(filename);
    json j;
    file >> j;

    Address addr;
    addr.country = j["country"];
    addr.city = j["city"];
    addr.street = j["street"];
    addr.latitude = j["latitude"];
    addr.longitude = j["longitude"];

    TrafficLight light(addr, j["offset"]);
    return light;
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    TrafficLight light1 = loadLight("traffic_light_1.json");
    TrafficLight light2 = loadLight("traffic_light_2.json");
    TrafficLight light3 = loadLight("traffic_light_3.json");

    while (true)
    {
        light1.GetInfo();
        light2.GetInfo();
        light3.GetInfo();
        std::this_thread::sleep_for(chrono::seconds(23));
    }

    return 0;
}