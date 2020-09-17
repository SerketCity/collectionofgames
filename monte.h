#ifndef MONTE_H
#define MONTE_H

#include <ctime>
#include <cmath>
#include <cstdlib>

#include "marble.h"
#include "card.h"

using namespace std;

/****************************************************************
*   STRUCTURE NAME: monte
*
*   builds monte template
*
*
****************************************************************/


template<class T>
class Monte
{ 
	public:
    		Monte(T);
    		void setThing1(T);
    		void setThing2(T);
		void setThing3(T);
		void shuffle();
		T pick(int);

	private:
    		T thingArray[3];
};

template<class T>
Monte<T>::Monte(T thingType)
{
        thingArray[0] = thingType;
}

/****************************************************************
*   FUNCTION NAME: setthing1
*  Description: sets first object in array
*
*   PARAMETERS: object type thing
*
*   RETURN VALUES: nothing
*
****************************************************************/


template<class T>
void Monte<T>::setThing1(T thing)
{
        thingArray[0] = thing;
}

/****************************************************************
*   FUNCTION NAME: setthing2
*  Description: sets second object in array
*
*   PARAMETERS: object type thing
*
*   RETURN VALUES: nothing
*
****************************************************************/

template<class T>
void Monte<T>::setThing2(T thing)
{
        thingArray[1] = thing;
}

/****************************************************************
*   FUNCTION NAME: setthing3
*  Description: sets third object in array
*
*   PARAMETERS: object type thing
*
*   RETURN VALUES: nothing
*
****************************************************************/

template<class T>
void Monte<T>::setThing3(T thing)
{
        thingArray[2] = thing;
}

/****************************************************************
*   FUNCTION NAME: shuffle
*  Description: shuffles objects in array
*
*   PARAMETERS: none
*
*   RETURN VALUES: none
*
****************************************************************/


template<class T>
void Monte<T>::shuffle()
{
        for(int i = 0; i < 3; i++)
        {
                int r = rand() % 3;
                T temp = thingArray[i];
                thingArray[i] = thingArray[r];
                thingArray[r] = temp;
        }
}

/****************************************************************
*   FUNCTION NAME: pick
*  Description: takes input for choice in array and returns it
*
*   PARAMETERS: int selection
*
*   RETURN VALUES: t type thing
*
****************************************************************/

template<class T>
T Monte<T>::pick(int select)
{
        T temp;
        switch(select)
        {
                case 1:
                        temp = thingArray[0];
                        break;
                case 2:
                        temp = thingArray[1];
                        break;
                case 3:
                        temp = thingArray[2];
                        break;
                default:
                        break;
        }
        return temp;

}


#endif
