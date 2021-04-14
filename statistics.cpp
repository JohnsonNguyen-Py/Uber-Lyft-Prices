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

float correlation(vector<float>& x, vector<float>& y)
{//start
    //# of elements to compare both vectors
    int xsize = x.size();

    int totalX = 0, totalY = 0, totalXY = 0;
    int squareX = 0, squareY = 0;

    for (int i = 0; i < xsize; i++)
    {//start loop

        //sum total of all vector x
        totalX += x.at(i);

        //sum total of all vector y
        totalY += y.at(i);

        //sum total of x*y
        totalXY = totalXY + x.at(i) * y.at(i);

        //sum of square vector elements
        squareX = squareX + x.at(i) * x.at(i);
        squareY = squareY + y.at(i) * y.at(i);
    }//end loop

    //calc correlation coefficient
    float corr = (float)(xsize * totalXY - totalX + totalY) / sqrt((xsize * squareX - totalX * totalX) * (xsize * squareY - totalY * totalY));

    return corr;
}//end
