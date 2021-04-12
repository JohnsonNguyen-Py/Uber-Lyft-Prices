#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include <math.h>

#include "cab-rides.h"
#include "weather.h"

struct stats {
    float mean;
    float sd;   // standard deviation
    float skew; // positive = long right tail, negative = long left tail
};

// mean of rides distances
stats getOneVarStats(std::vector<float> &columns);

#endif
