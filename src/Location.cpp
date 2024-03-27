#include "Location.h"

Location::Location() { r = 0; c = 0; }
Location::Location(int raw, int col)
{
	r = raw;
	c = col;
}


std::ostream& operator<<(std::ostream& os, const Location& loc)
{
	os << "(" << loc.r << " , " << loc.c << " ) ";
	return os;
}

Location::Location(string loc)
{
	r = (int)loc[0] - 97;
	c = (int)loc[1]-'1';
}

bool Location::operator==(const Location& loc)
{
	return loc.r == r && loc.c == c;
}

bool Location::operator!=(const Location& loc)
{
	return loc.r != r || loc.c != c;
}

Location Location::operator+(Location loc)
{
	return Location(loc.r + r, loc.c + c);
}

Location Location::operator+=(Location loc)
{
	r += loc.r;
	c += loc.c;
	return *this;
}