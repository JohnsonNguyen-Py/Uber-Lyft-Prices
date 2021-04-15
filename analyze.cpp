#include <vector>
#include <string>
#include <iostream>

#include "cab-rides.h"
#include "weather.h"
#include "statistics.h"

using namespace std;

int main() {
    CabRides rides("cab_rides.csv");
    Weather weather("weather.csv");

    stats price_stats = getOneVarStats(rides.prices);
    stats distance_stats = getOneVarStats(rides.distances);
    stats temp_stats = getOneVarStats(weather.temps);
    linearFit price_distance_fit = getLinearFit(rides.distances, rides.prices);

    cout << "[price stats]" << endl << price_stats << endl << endl;
    cout << "[distance stats]" << endl << distance_stats << endl << endl;
    cout << "[temp stats]" << endl <<  temp_stats << endl << endl;

    cout << "[price vs. distance linear fit]" << endl << price_distance_fit << endl << endl;

    CabRides uberRides = rides.getUberRides();
    CabRides lyftRides = rides.getLyftRides();

    stats uber_price_stats = getOneVarStats(uberRides.prices);
    stats lyft_price_stats = getOneVarStats(lyftRides.prices);
    linearFit uber_price_distance_fit = getLinearFit(uberRides.distances, uberRides.prices);
    linearFit lyft_price_distance_fit = getLinearFit(lyftRides.distances, lyftRides.prices);

    cout << "[price stats (Uber Only)]" << endl << uber_price_stats << endl << endl;
    cout << "[price stats (Lyft Only)]" << endl << lyft_price_stats << endl << endl;
    cout << "[price vs. distance (Uber Only) linear fit]" << endl << uber_price_distance_fit << endl << endl;
    cout << "[price vs. distance (Lyft Only) linear fit]" << endl << lyft_price_distance_fit << endl << endl;
}
