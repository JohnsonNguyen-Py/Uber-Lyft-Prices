#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>

#include "cab-rides.h"

using namespace std;


ostream& operator<<(ostream& os, const CabType& ct)
{
    switch(ct) {
        case CabType::Lyft: os << "Lyft"; break;
        case CabType::Uber: os << "Uber"; break;
        case CabType::UNKNOWN: os << "UNKNOWN"; break;
    }
    return os;
}

CabRides::CabRides(const string& filename) {
	fstream table(filename, ios::in);
	string line;
	char dummy_char;
	string dummy_string;

	getline(table, line); // skip first line

	while ( getline(table, line) ) {
		// table format: distance, cab_type, time_stamp, destination, source,
		// price, surge_multiplier, id, product_id, name

		stringstream ss(line);
		float distance;
		ss >> distance;

		// cab_type is slightly more involved
		string service;
		ss.get(dummy_char); // skip the comma
		getline(ss, service, ',');

		long long time_stamp;
		ss >> time_stamp;

		// destination
		ss.get(dummy_char);
		getline(ss, dummy_string, ',');
		// source
		getline(ss, dummy_string, ',');

		if ( ss.peek() == ',') continue; // Do NOT use rows with missing values
		float price;
		ss >> price;

		// surge_multiplier
		ss.get(dummy_char);
		getline(ss, dummy_string, ',');
		// id
		ss.get(dummy_char);
		getline(ss, dummy_string, ',');

		string product_name;
		getline(ss, product_name, ',');

		distances.push_back(distance);
		if ( service == "Lyft" ) {
			cab_types.push_back(CabType::Lyft);
		} else if ( service == "Uber" ) {
			cab_types.push_back(CabType::Uber);
		} else {
			cab_types.push_back(CabType::UNKNOWN);
		}
		time_stamps.push_back(time_stamp);
		prices.push_back(price);
		product_names.push_back(product_name);
	}
}

CabRides CabRides::getUberRides() {
    CabRides c;
    for (auto i = 0; i < cab_types.size(); i++) {
        if ( cab_types.at(i) == CabType::Uber ) {
            c.distances.push_back(distances.at(i));
            c.cab_types.push_back(cab_types.at(i));
            c.time_stamps.push_back(time_stamps.at(i));
            c.prices.push_back(prices.at(i));
            c.product_names.push_back(product_names.at(i));
        }
    }

    return c;
}

CabRides CabRides::getLyftRides() {
    CabRides c;
    for (auto i = 0; i < cab_types.size(); i++) {
        if ( cab_types.at(i) == CabType::Lyft ) {
            c.distances.push_back(distances.at(i));
            c.cab_types.push_back(cab_types.at(i));
            c.time_stamps.push_back(time_stamps.at(i));
            c.prices.push_back(prices.at(i));
            c.product_names.push_back(product_names.at(i));
        }
    }

    return c;
}
