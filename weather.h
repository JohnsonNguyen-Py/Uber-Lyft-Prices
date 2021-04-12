#ifndef WEATHER_H
#define WEATHER_H

class Weather
{
public:
    std::vector<float> temps;
    std::vector<float> rain;
    std::vector<int> time_stamps;
    void vectorDataInsert();
};

#endif
