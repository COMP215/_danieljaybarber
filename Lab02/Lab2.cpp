#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void GenerateStrings(int num_strings, int character_size, string file_name);
void SortStrings(int num_strings, string file_name);

int main()
{
	int num_strings = 10000;		// The number of strings generated per file.
	int character_size = 60;		// The length of each string generated.

	GenerateStrings(num_strings, character_size, "test1.txt");
	GenerateStrings(num_strings, character_size, "test2.txt");
	GenerateStrings(num_strings, character_size, "test3.txt");
	SortStrings(num_strings, "test1.txt");
	SortStrings(num_strings, "test2.txt");
	SortStrings(num_strings, "test3.txt");

	return 0;
}

void GenerateStrings(int num_strings, int character_size, string file_name) 
{
	ofstream file_write;		// Opens a new filestream.

	file_write.open(file_name.c_str());

	for (int i = 0; i < num_strings; ++i)
	{
		string new_word = "";	// Temp var to hold a newly created word.

		for (int a = 0; a < character_size; a++)	
		{
			new_word += (char) (97 + rand() % 26);
		} // End of For

		file_write << new_word << endl;
		
	} // End of For

	file_write.close();	
	
}

void SortStrings(int num_strings, string file_name)
{

	ifstream file_read;				// Opens a new filestream.

	vector<string> stringVector;	// A new vector to hold strings from file.

	file_read.open(file_name.c_str());

	int num_lines = 0;				// Counter for lines in file.

	if (file_read.is_open())
	{
		
		while (!file_read.eof())
		{
			
			string oneLine;			// Temp string to hold current lines value.

			getline(file_read, oneLine);

			stringVector.insert(stringVector.begin() + num_lines, oneLine);
 			
			num_lines++;

		} // End while loop
		
	} //End if

	sort (stringVector.begin(), stringVector.begin()+num_lines);

	for (int i = 0; i < num_lines - 1; ++i)
	{
		cout << i << ". " << stringVector[i] << endl;	

	}
	file_read.close();
    //===========================================

	cout << "END OF PROGRAM" << endl << endl;

}
