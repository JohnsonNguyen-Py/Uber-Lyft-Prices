#include <vector>
#include <math.h>
#include <assert.h>
#include <iostream>

#include "statistics.h"

using namespace std;

// get mean, standard deviation, and skew of column
stats getOneVarStats(vector<float>& column) {
    stats s;
    assert(column.size() != 0);
    long n = 0;
    double accum = 0.0;
    double accum_sq = 0.0;

    for (auto& data : column) {
        accum += data;
        accum_sq += data * data;
        n++;
    }

    s.mean = accum / (double) n;
    s.sd = sqrt((accum_sq / (double)(n - 1)) - (s.mean * s.mean));

    double accum_cub = 0.0;

    for (auto& data : column) {
        accum_cub += pow(data - s.mean, 3);
    }

    s.skew = accum_cub / (double)(n - 1) / pow(s.sd, 3);

    return s;
}

linearFit getLinearFit(vector<float>& x, vector<float>& y) {
    linearFit lf;

    long long n = x.size() <= y.size() ? x.size() : y.size();
    double xAccum = 0.0;
    double xAccum_sq = 0.0;
    double yAccum = 0.0;
    double yAccum_sq = 0.0;
    double xyAccum = 0.0;

    for (int i = 0; i < n; i++) {
        double xi = x.at(i);
        double yi = y.at(i);
        xAccum += xi;
        yAccum += yi;
        xAccum_sq += xi * xi;
        yAccum_sq += yi * yi;
        xyAccum += xi * yi;
    }

    double count = (double) n;
    double numerator = double(n * xyAccum) - xAccum * yAccum;
    double denom = double(n * xAccum_sq - xAccum * xAccum) * (double(n * yAccum_sq) - yAccum * yAccum);
    lf.correlation = numerator / sqrt(denom);

    double xMean = xAccum / count;
    double xsd = sqrt((xAccum_sq / count) - (xMean * xMean));
    double yMean = yAccum / count;
    double ysd = sqrt((yAccum_sq / count) - (yMean * yMean));

    lf.slope = lf.correlation * ysd / xsd;
    lf.intercept = yMean - lf.slope * xMean;

    return lf;
}

CabRides::CabRides() {}

ostream& operator<<(std::ostream& os, const stats s)
{
    os << "mean: " << s.mean
        << " stdev: " << s.sd
        << " skew: " << s.skew;
    return os;
}

ostream& operator<<(std::ostream& os, const linearFit lf)
{
    os << "slope: " << lf.slope
        << " intercept: " << lf.intercept
        << " correlation: " << lf.intercept;
    return os;
}
