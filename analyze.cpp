#include <vector>
#include <string>
#include <iostream>

#include "cab-rides.h"
#include "weather.h"
#include "statistics.h"

using namespace std;

CabRides getRideTestData() {
    vector<CabType> cab_types(15, CabType::Lyft);
    vector<CabType> ubers(15, CabType::Uber);
    cab_types.insert(cab_types.end(), ubers.begin(), ubers.end());

    CabRides r = {
        {
            10.0, 10.0, 10.0, 10.0, 11.0, 11.0, 12.0, 12.0, 13.0, 14.0, 15.0,
            16.0, 17.0, 18.0, 19.0,
            10.0, 10.0, 10.0, 10.0, 11.0, 11.0, 12.0, 12.0, 13.0, 14.0, 15.0,
            16.0, 17.0, 18.0, 19.0
        },
        cab_types,
        {
            7, 10, 5, 11, 6, 9, 2, 1, 4, 8, 14, 12, 3, 0, 13,
            13, 12, 7, 2, 14, 3, 4, 10, 9, 0, 11, 1, 8, 6, 5
        },

        {
            21.83070, 23.77734, 21.98066, 22.35094, 25.34288,
            24.54997, 26.77077, 25.85557, 26.64197, 28.79596,
            31.49976, 34.10198, 34.53185, 38.73401, 39.70895,
            17.19143, 15.51235, 15.54780, 17.81076, 18.39082,
            18.01110, 20.85211, 20.57887, 21.94923, 23.16039,
            22.99939, 25.79663, 27.18243, 27.28597, 31.01332
        },

        vector<std::string>(30, "normal")
    };

    return r;
}

Weather getWeatherTestData() {
    Weather w = {
        {
            46.2, 35.8, 37.8, 39.3, 40.7, 33.9, 36.8, 40.5, 48.9, 35.0, 42.4,
            38.6, 36.9, 39.2, 37.9
        },
        {
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.2, 0.2, 0.2, 1.0
        },
        {
            0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14
        }
    };

    return w;
}

int main() {
    auto rides = getRideTestData();
    stats price_stats = getOneVarStats(rides.prices);
    stats distance_stats = getOneVarStats(rides.distances);

    cout << "[price stats] mean: " << price_stats.mean
        << " stdev: " << price_stats.sd
        << " skew: " << price_stats.skew << endl;

    cout << "[distance stats] mean: " << distance_stats.mean
        << " stdev: " << distance_stats.sd
        << " skew: " << distance_stats.skew << endl;
}
