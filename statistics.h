#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include <math.h>
#include <iostream>

#include "cab-rides.h"
#include "weather.h"

struct stats {
    float mean;
    float sd;   // standard deviation
    float skew; // positive = long right tail, negative = long left tail
};

struct linearFit {
    float slope;
    float intercept;
    float correlation;
};

// mean of rides distances
stats getOneVarStats(std::vector<float> &columns);
linearFit getLinearFit(std::vector<float>& x, std::vector<float>& y);
std::ostream& operator<<(std::ostream& os, stats s);
std::ostream& operator<<(std::ostream& os, linearFit lf);

#endif
