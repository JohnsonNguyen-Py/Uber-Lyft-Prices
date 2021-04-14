#include <vector>
#include <math.h>
#include <assert.h>

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
