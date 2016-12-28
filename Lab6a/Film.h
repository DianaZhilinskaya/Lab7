#pragma once 
#include <iostream>

using namespace std;
class Film 
{
public:
	Film(int,string);
	string name;
	int god;
	Film();
	friend ostream& operator<<(ostream& ost, Film& s);
	 bool operator==(Film& re);
};