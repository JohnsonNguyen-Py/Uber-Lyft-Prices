#ifndef CAB_RIDES_ROW_H
#define CAB_RIDES_ROW_H

#include <string>

enum CabType
{
    Lyft, Uber
};

class CabRidesRow
{
public:
    float distance;
    CabType cab_type;
    int time_stamp;
    float price;
    std::string product_name;
    void vectorDataInsert();
};

#endif
