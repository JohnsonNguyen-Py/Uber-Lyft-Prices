#ifndef WEATHER_ROW_H
#define WEATHER_ROW_H

#include <string>
#include <vector>

using namespace std;

class WeatherRow
{
public:
    //travel distances ride
    //float
    vector <string> temp;

    //prices of service
    //float
    vector <string> rain;

    //time stamp of each ride 
    //int
    vector <string> time_stamp;

    //every other uneeded data pt
    vector <string> misc;
    //function to insert data from csv file 

    void vectorWeatherDataInsert();
};

#endif
