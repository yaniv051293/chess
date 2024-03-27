#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Location
{
	int r;
	int c;
	Location() ;
	Location(int col,int raw);
	Location(string loc);
	friend std::ostream& operator<<(std::ostream& os, const Location& loc);
	bool operator==(const Location& loc);
	bool operator!=(const Location& loc);
	Location operator+(Location loc);
	Location operator+=(Location loc);

};
