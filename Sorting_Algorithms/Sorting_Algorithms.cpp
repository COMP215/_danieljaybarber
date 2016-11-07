#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

void mergeSort(int* array_one, int array_start, int counter);
void bubbleSort(int* array_one, int counter);
void selectionSort(int* array_one, int array_size);

int main()
{
	int array_one[50] = {2, 42, 25, 72, 17, 80, 5};
	int counter = 6;
	
	//for (int i = 0; i < 50; ++i)
		//array_one[i] = 0;

	//selectionSort(array_one, counter);
	//bubbleSort(array_one, counter);
	mergeSort(array_one, 0, counter);
	/*
	for (int i = 0; i < counter; ++i)
		cout << array_one[i] << endl;
*/
	return 0;
}

void mergeSort(int* array_one, int array_start, int array_size)
{
	int mid = floor((0 + array_size) / 2);

	int temp[mid], temp2[mid];
	int b = 0;

	for (int i = 0; i < mid; ++i)
	{
		temp[i] = array_one[i];
	}
	for (int i = mid; i <= array_size; ++i)
	{
		temp2[b] = array_one[i];
		b++;
	}


}

void selectionSort(int* array_one, int array_size)
{
	int min_index;
	for (int i = 0; i < array_size; ++i)
	{
		min_index = i;
		for (int j = i; j < array_size; ++j)
		{
			if (array_one[min_index] > array_one[j])
			{
				min_index = j;
			}
		}
		swap(array_one[i], array_one[min_index]);
	}
}

void bubbleSort(int* array_one, int counter)
{
	// Sorts the array
	for (int i = 0; i < counter; ++i)
	{
		for (int j = 0; j < counter - i - 1; ++j)
		{
			if (array_one[j + 1] < array_one[j])
			{
				int temp = array_one[j];
				array_one[j] = array_one[j + 1];
				array_one[j + 1] = temp;
 			}
		}
	}

}