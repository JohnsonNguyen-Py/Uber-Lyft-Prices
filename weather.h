#ifndef WEATHER_H
#define WEATHER_H
#include <vector>

class Weather
{
public:
    std::vector<float> temps;
    //std::vector<vectorWeatherDataInsert> vectorWeatherDataInsert;
    std::vector<float> rain;
    std::vector<long long> time_stamps;
};

#endif
