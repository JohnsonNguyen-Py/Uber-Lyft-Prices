#ifndef CAB_RIDES_ROW_H
#define CAB_RIDES_ROW_H

#include <string>

using namespace std;

enum CabType {
    Lyft, Uber
};

class CabRidesRow {
public:
    float distance;
    CabType cab_type;
    int time_stamp;
    float price;
    string product_name;
};

#endif
