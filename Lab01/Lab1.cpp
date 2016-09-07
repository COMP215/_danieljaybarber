#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void exerciseOne(int numberOfStrings, int numberOfChars, string fileName);
void exerciseTwo(int arraySize, string fileName);
void exerciseThree();

int main()
{
	exerciseThree();
}

void exerciseOne(int numberOfStrings, int numberOfChars, string fileName) 
{
	ofstream myfile;

	myfile.open(fileName.c_str());

	for (int i = 0; i < numberOfStrings; ++i)
	{
		string new_word = "";

		for (int a = 0; a < numberOfChars; a++)	
		{
			new_word += (char) (97 + rand() % 26);
		} // End of For

		myfile << new_word << endl;
		
	} // End of For

	myfile.close();	
	
}

void exerciseTwo(int arraySize, string fileName)
{

	ifstream myFile;

	vector<string> stringVector;

	myFile.open(fileName.c_str());

	int x = 0;

	if (myFile.is_open())
	{
		
		while (!myFile.eof())
		{
			
			string oneLine;

			getline(myFile, oneLine);

			stringVector.insert(stringVector.begin() + x, oneLine);
 			
			x++;

		} // End while loop
		
	} //End if

	sort (stringVector.begin(), stringVector.begin()+x);

	for (int i = 0; i < x - 1; ++i)
	{
		cout << i << ". " << stringVector[i] << endl;	

	}
	myFile.close();
    //===========================================

	cout << "END OF PROGRAM" << endl << endl;

}

void exerciseThree()
{

	int arraySize = 10000000;
	int charSize = 60;

	exerciseOne(arraySize, charSize, "test1.txt");
	exerciseOne(arraySize, charSize, "test2.txt");
	exerciseOne(arraySize, charSize, "test3.txt");
	exerciseTwo(arraySize, "test1.txt");
	exerciseTwo(arraySize, "test2.txt");
	exerciseTwo(arraySize, "test3.txt");

}
