//
//  Graph.hpp
//
//

#ifndef Exam1_hpp
#define Exam1_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Mushrooms{
public:
	Mushrooms();
	string common_name;
	string scientific_name;
	int quantity;
	int weight;
	int value;
	int weighted_value;
};

class Satchel{
public:
	Satchel();
	int size;
	vector<Mushrooms*> mushroom_vector;	
};




#endif /* Exam1_hpp */