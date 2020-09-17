#ifndef MARBLE_H
#define MARBLE_H

#include <string>

using namespace std;

class Marble
{
	private:
	  string color;

  	public:
    	  Marble();
	  Marble(string);
	  void setColor(string);
	  string getColor();	
};

#endif

