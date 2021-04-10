#include <iostream>
#include <vector>
#include <fstream>
#include "weather-row.h"

using namespace std;

void WeatherRow::vectorDataInsert()
{//start vector data insert
	
	//opening file
	fstream weather;

	weather.open("weather.csv", ios::in);

	//start entring data
	vector<string> row;

	string line, word, place;

	while (weather >> place)
	{//start reading row
		weather.clear();

		//row of data is in line variable
		getline(weather, line);

		stringstream break(line);//breaks line into each data val

		while (getline(break, word, ','))
		{//reads column val in row 
			//add column val into vector
			weather.push_back(word);
		}

	}//end reading row

	//close file
	weather.close();

}//end vector data insert