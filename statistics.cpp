#include <vector>
#include <math.h>
#include <assert.h>

#include "statistics.h"

using namespace std;

// mean of rides distances
stats getRideDistanceStats(vector<CabRidesRow> rides) {
    stats s;
    assert(rides.size() != 0);
    int n = 0;
    float accum = 0.0;
    float accum_sq = 0.0;

    for (auto& r : rides) {
        accum += r.distance;
        accum_sq += r.distance * r.distance;
        n++;
    }

    s.mean = accum / (float) n;
    s.sd = sqrt((accum_sq / (float)(n - 1)) - (s.mean * s.mean));

    float accum_cub = 0.0;

    for (auto& r : rides) {
        accum_cub += pow(r.distance - s.mean, 3);
    }

    s.skew = accum_cub / (float)(n - 1) / pow(s.sd, 3);

    return s;
}

stats getRidePriceStats(vector<CabRidesRow> rides) {
    stats s;
    assert(rides.size() != 0);
    int n = 0;
    float accum = 0.0;
    float accum_sq = 0.0;

    for (auto& r : rides) {
        accum += r.price;
        accum_sq += r.price * r.price;
        n++;
    }

    s.mean = accum / (float) n;
    s.sd = sqrt((accum_sq / (n - 1)) - (s.mean * s.mean));

    float accum_cub = 0.0;

    for (auto& r : rides) {
        accum_cub += pow(r.price - s.mean, 3);
    }

    s.skew = accum_cub / (float)(n - 1) / pow(s.sd, 3);

    return s;
}
