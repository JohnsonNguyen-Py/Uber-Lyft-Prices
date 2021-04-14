#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "weather.h"

using namespace std;

void WeatherRow::vectorWeatherDataInsert()
{//start vector data insert

	//opening file
	fstream weather;

	weather.open("weather.csv", ios::in);

	//clear data vector
	temp.clear();
	rain.clear();
	time_stamp.clear();
	misc.clear();

	string line, word, place;

	while (weather >> place)
	{//start reading row

		//row of data is in line variable
		getline(weather, line);

		//breaks line into each data val
		stringstream broken(line);

		//two int vairable to make counter
		//counter makes it possible to put data in specifc data vector
		int hold = 0;
		int specific;

		while (getline(broken, word, ','))
		{//start reading column val in row
			specific = hold % 8;
			/*
			specific = 0 - 7
			0 = weather temp
			4 = rain
			5 = time stamp
			other numb = unneeded data
			*/

			//start putting data val into vectors
			if (specific == 0)
			{//place data val into distance val
				temp.push_back(word);
			}
			else if (specific == 4)
			{//place data val into cab_type
				rain.push_back(word);
			}
			else if (specific == 5)
			{//place data val into time_stamp
				time_stamp.push_back(word);
			}
			else
			{//place data val into misc
				misc.push_back(word);
			}


			//make sure specific stays between 0 - 9
			if (hold < 8)
			{
				hold++;
			}
			else
			{
				hold = 0;
			}
		}//end reading column val in row

	}//end reading row

	//close file
	weather.close();

}//end vector data insert
