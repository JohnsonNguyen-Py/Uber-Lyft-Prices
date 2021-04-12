#include <vector>
#include <math.h>
#include <assert.h>

#include "statistics.h"

using namespace std;

// get mean, standard deviation, and skew of column
stats getOneVarStats(vector<float>& column) {
    stats s;
    assert(column.size() != 0);
    int n = 0;
    float accum = 0.0;
    float accum_sq = 0.0;

    for (auto& data : column) {
        accum += data;
        accum_sq += data * data;
        n++;
    }

    s.mean = accum / (float) n;
    s.sd = sqrt((accum_sq / (float)(n - 1)) - (s.mean * s.mean));

    float accum_cub = 0.0;

    for (auto& data : column) {
        accum_cub += pow(data - s.mean, 3);
    }

    s.skew = accum_cub / (float)(n - 1) / pow(s.sd, 3);

    return s;
}
