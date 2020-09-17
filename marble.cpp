#include <string>
#include "marble.h"

using namespace std;

Marble::Marble()
{
	color = "Blue";
}

Marble::Marble(string s)
{
	color = s;
}

void Marble::setColor(string s)
{
	color = s;
}

string Marble::getColor()
{
	return color;
}
