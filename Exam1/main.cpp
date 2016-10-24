
#include <fstream>
#include "Exam1.hpp"
#include <iostream>
#include <string>
#include <algorithm>

void printToScreen();	

int main()
{
	vector<Mushrooms> forrest_mushrooms;
	vector<Mushrooms> sorted_vector;
	vector<Mushrooms> my_satchel;
	Mushrooms temp_mushroom1;
	Mushrooms smallest_mushroom;
	Mushrooms temp_mushroom2;

	Satchel mySatchel;
	mySatchel.size = 35;
	int totalSize = 0;
	int satchel_size = 0;
	int vect_counter = 0;

	ifstream myfile;

	string fileName = "input.csv";

	myfile.open(fileName.c_str());

	if (myfile.is_open())
	{
		int temp_int;
		string oneLine;
		while (!myfile.eof())
		{
			Mushrooms a;

			getline(myfile, oneLine, ',');
			a.common_name = oneLine;
			getline(myfile, oneLine, ',');
			a.scientific_name = oneLine;
			getline(myfile, oneLine, ',');
			int quantity = atoi( oneLine.c_str() );
			a.quantity = quantity;
			a.weight = quantity;
			getline(myfile, oneLine, '\n');
			int value = atoi( oneLine.c_str() );
			a.value = value;	

			a.weighted_value = a.value / a.weight;	

			forrest_mushrooms.push_back(a);	
			vect_counter++;
		}
	}
	else
	{
		cout << "No file found!" << endl;
		return -1;
	}
	
	int hmrt = 0;
	while (totalSize <= mySatchel.size)
	{
		hmrt = 0;
		smallest_mushroom = forrest_mushrooms[0];


		for (int i = 0; i < vect_counter; ++i)
		{
			temp_mushroom1 = forrest_mushrooms[i];
			if (temp_mushroom1.weighted_value <= smallest_mushroom.weighted_value)
			{
				smallest_mushroom = temp_mushroom1;
			}

		} // End for


		while (hmrt < smallest_mushroom.quantity)
		{
			my_satchel.push_back(smallest_mushroom);
			totalSize = totalSize + smallest_mushroom.weight;
			hmrt++;
			satchel_size++;
			cout << hmrt << " - " << smallest_mushroom.quantity << endl;
		}

		cout << totalSize << endl;

	} //End while

	for (int i = 0; i < satchel_size; ++i)
	{
		temp_mushroom2 = my_satchel[i];
		cout << temp_mushroom2.common_name << " - " << temp_mushroom2.weighted_value << endl;
	}

} // End Main

void printToScreen()
{


}

