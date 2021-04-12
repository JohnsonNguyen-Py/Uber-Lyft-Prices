#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "cab-rides-row.h"

using namespace std;

void CabRidesRow::vectorRideDataInsert()
{//start vector data insert

	//opening file
	fstream ride;

	ride.open("cab_rides.csv", ios::in);

	//clear data vector
	distance.clear();
	price.clear();
	time_stamp.clear();
	product_name.clear();
	cab_type.clear();
	misc.clear();

	//start entering data
	string line, word, place;

	while (ride >> place)
	{//start reading rows 

		//puts row of data into line
		getline(ride, line);

		//break words up
		stringstream broken(line);

		//two int vairable to make counter
		//counter makes it possible to put data in specifc data vector
		int hold = 0;
		int specific;
		while (getline(broken, word, ','))
		{//start reading column val in row 
			specific = hold % 10;

			/*
			* based off what the csv file is and with no changes to the file
			* the range that specific is in are the cols that data is in
			specific = 0 - 9
			0 = distance
			1 = cab type
			2 = time stamp
			5 = price
			9 = product name
			other numb = misc data
			*/

			
			//start putting data val into specifc vectors
			if (specific == 0)
			{//place data val into distance val
				distance.push_back(word);
			}
			else if (specific == 1)
			{//place data val into cab_type
				cab_type.push_back(word);
			}
			else if (specific == 2)
			{//place data val into time_stamp
				time_stamp.push_back(word);
			}
			else if (specific == 5)
			{//place data val into price
				price.push_back(word);
			}
			else if (specific == 9)
			{//place data val into cab_type
				product_name.push_back(word);
			}
			else
			{//place data val into misc
				misc.push_back(word);
			}

			//make sure specific stays between 0 - 9
			if (hold < 10)
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
	ride.close();

}//end vector data insert