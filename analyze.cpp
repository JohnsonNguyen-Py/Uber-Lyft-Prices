#include <vector>
#include <string>
#include <iostream>

#include "cab-rides.h"
#include "weather.h"
#include "statistics.h"

using namespace std;

int main() {
    CabRides rides("test_cab_rides.csv");
    Weather weather("test_weather.csv");
    // DEBUG
    stats price_stats = getOneVarStats(rides.prices);
    stats distance_stats = getOneVarStats(rides.distances);
    stats weather_stats = getOneVarStats(weather.temps);

    cout << "[price stats] mean: " << price_stats.mean
        << " stdev: " << price_stats.sd
        << " skew: " << price_stats.skew << endl;

    cout << "[distance stats] mean: " << distance_stats.mean
        << " stdev: " << distance_stats.sd
        << " skew: " << distance_stats.skew << endl;

    cout << "[temp stats] mean: " << weather_stats.mean
        << " stdev: " << weather_stats.sd
        << " skew: " << weather_stats.skew << endl;
}
