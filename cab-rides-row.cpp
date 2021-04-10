#include <iostream>
#include <vector>
#include <fstream>
#include "cab-rides-row.h"

using namespace std;

void CabRidesRow::vectorDataInsert()
{//start vector data insert

	//opening file
	fstream ride;

	ride.open("weather.csv", ios::in);

	//start entring data
	vector<string> row;

	string line, word, place;

	while (weather >> place)
	{//start reading row
		ride.clear();

		//row of data is in line variable
		getline(ride, line);

		stringstream break(line);//breaks line into each data val

		while (getline(break, word, ','))
		{//reads column val in row 
			//add column val into vector
			ride.push_back(word);
		}

	}//end reading row

	//close file
	ride.close();

}//end vector data insert