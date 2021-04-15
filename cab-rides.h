#ifndef CAB_RIDES_H
#define CAB_RIDES_H

#include <string>
#include <vector>

enum CabType
{
    Lyft, Uber, UNKNOWN
};

class CabRides
{
public:
    std::vector<float> distances;
    std::vector<CabType> cab_types;
    std::vector<long long> time_stamps;
    std::vector<float> prices;
    std::vector<std::string> product_names;

    CabRides(const std::string& filename);
    CabRides();

    CabRides getUberRides();
    CabRides getLyftRides();
};

#endif
