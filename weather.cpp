#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include "weather.h"

using namespace std;

Weather::Weather(const string& filename) {
	fstream table(filename, ios::in);
	string line;
	char dummy_char;
	string dummy_string;

	getline(table, line); // skip first line

	while ( getline(table, line) ) {
		// table format: temp, location, clouds, pressure, rain, time_stamp
		// humidity, wind,

		stringstream ss(line);
		float temp;
		ss >> temp;

		// location
		ss.get(dummy_char); // skip the comma
		getline(ss, dummy_string, ',');
		// clouds
		getline(ss, dummy_string, ',');
		// pressure
		getline(ss, dummy_string, ',');

		// rain
		float rain_data;
		if ( ss.peek() == ',') {
			rain_data = 0.0;
		} else {
			ss >> rain_data;
		}

		ss.get(dummy_char);
		long long time_stamp;
		ss >> time_stamp;

		temps.push_back(temp);
		rain.push_back(rain_data);
		time_stamps.push_back(time_stamp);
	}
}
