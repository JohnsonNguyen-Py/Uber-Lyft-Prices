#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include <math.h>

#include "cab-rides-row.h"
#include "weather-row.h"

struct stats {
    float mean;
    float sd;   // standard deviation
    float skew; // positive = long right tail, negative = long left tail
};

// mean of rides distances
stats getRideDistanceStats(std::vector<CabRidesRow> rides);
stats getRidePriceStats(std::vector<CabRidesRow> rides);

#endif
