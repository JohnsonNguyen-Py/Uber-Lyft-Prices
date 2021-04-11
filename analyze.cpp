#include <vector>
#include <iostream>

#include "cab-rides-row.h"
#include "weather-row.h"
#include "statistics.h"

using namespace std;

vector<CabRidesRow> getRideTestData() {
    vector<CabRidesRow> rows = {
        // distance, cab_type, time_stamp, price, product_name
        // price = (distance + noise(mean=1, std=0.4)) * 2
        { 10.0, CabType::Lyft, 7, 21.83070, "normal" },
        { 10.0, CabType::Lyft, 10, 23.77734, "normal" },
        { 10.0, CabType::Lyft, 5, 21.98066, "normal" },
        { 10.0, CabType::Lyft, 11, 22.35094, "normal" },
        { 11.0, CabType::Lyft, 6, 25.34288, "normal" },
        { 11.0, CabType::Lyft, 9, 24.54997, "normal" },
        { 12.0, CabType::Lyft, 2, 26.77077, "normal" },
        { 12.0, CabType::Lyft, 1, 25.85557, "normal" },
        { 13.0, CabType::Lyft, 4, 26.64197, "normal" },
        { 14.0, CabType::Lyft, 8, 28.79596, "normal" },
        { 15.0, CabType::Lyft, 14, 31.49976, "normal" },
        { 16.0, CabType::Lyft, 12, 34.10198, "normal" },
        { 17.0, CabType::Lyft, 3, 34.53185, "normal" },
        { 18.0, CabType::Lyft, 0, 38.73401, "normal" },
        { 19.0, CabType::Lyft, 13, 39.70895, "normal" },

        // price = (distance + noise(mean=1, std=0.4)) * 1.5
        { 10.0, CabType::Uber, 13, 17.19143, "normal" },
        { 10.0, CabType::Uber, 12, 15.51235, "normal" },
        { 10.0, CabType::Uber, 7, 15.54780, "normal" },
        { 10.0, CabType::Uber, 2, 17.81076, "normal" },
        { 11.0, CabType::Uber, 14, 18.39082, "normal" },
        { 11.0, CabType::Uber, 3, 18.01110, "normal" },
        { 12.0, CabType::Uber, 4, 20.85211, "normal" },
        { 12.0, CabType::Uber, 10, 20.57887, "normal" },
        { 13.0, CabType::Uber, 9, 21.94923, "normal" },
        { 14.0, CabType::Uber, 0, 23.16039, "normal" },
        { 15.0, CabType::Uber, 11, 22.99939, "normal" },
        { 16.0, CabType::Uber, 1, 25.79663, "normal" },
        { 17.0, CabType::Uber, 8, 27.18243, "normal" },
        { 18.0, CabType::Uber, 6, 27.28597, "normal" },
        { 19.0, CabType::Uber, 5, 31.01332, "normal" }
    };

    return rows;
}

vector<WeatherRow> getWeatherTestData() {
    vector<WeatherRow> rows = {
        // temp, rain, time_stamp
        // it was dry... then it was raining
        { 46.2, 0.0, 0},
        { 35.8, 0.0, 1},
        { 37.8, 0.0, 2},
        { 39.3, 0.0, 3},
        { 40.7, 0.0, 4},
        { 33.9, 0.0, 5},
        { 36.8, 0.0, 6},
        { 40.5, 0.0, 7},
        { 48.9, 0.0, 8},
        { 35.0, 0.0, 9},
        { 42.4, 0.0, 10},
        { 38.6, 0.2, 11},
        { 36.9, 0.2, 12},
        { 39.2, 0.2, 13},
        { 37.9, 1.0, 14}
    };

    return rows;
}

int main() {
    auto rides = getRideTestData();
    stats price_stats = getRidePriceStats(rides);
    stats distance_stats = getRideDistanceStats(rides);

    cout << "[price stats] mean: " << price_stats.mean
        << " stdev: " << price_stats.sd
        << " skew: " << price_stats.skew << endl;

    cout << "[distance stats] mean: " << distance_stats.mean
        << " stdev: " << distance_stats.sd
        << " skew: " << distance_stats.skew << endl;
}
