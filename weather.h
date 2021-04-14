#ifndef WEATHER_H
#define WEATHER_H
#include <vector>

class Weather
{
public:
    Weather(const std::string& filename);
    std::vector<float> temps;
    std::vector<float> rain;
    std::vector<long long> time_stamps;
};

#endif
