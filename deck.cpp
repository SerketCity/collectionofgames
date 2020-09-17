#include "deck.h"
#include <cmath>
#include <cstdlib>

/****************************************************************
*   STRUCTURE NAME: deck
*
*   builds deck object that holds a 52 card array
*                                  
*  
****************************************************************/

Deck::Deck()
{
  for(int i = 0; i < 4; i++)
	{
		Suit y;
		if(i == 0)
			y = CLUBS;
		if(i == 1)
			y = DIAMONDS;
		if(i == 2)
			y = HEARTS;
		if(i == 3)
			y = SPADES;

		for(int x = 1; x < 14; x++)
		{
			push(Card(x, y));
		}
	}
}

/****************************************************************
*   FUNCTION NAME: deal
*  Description: deals card
*
*   PARAMETERS: none
*  
*   RETURN VALUES: Card
*
****************************************************************/

Card Deck::deal()
{
  Card cardTemp = pop();
  return cardTemp;
}

/****************************************************************
*   FUNCTION NAME: shuffle
*  Description: shuffles all cards in the deck
*
*   PARAMETERS: none
*  
*   RETURN VALUES: void
*
****************************************************************/

void Deck::shuffle()
{
	if(isEmpty())
  	{
    		cout<<"Deck is empty!"<<endl;
  	}
  	else
  	{
		Stack tempstack1;
		Stack tempstack2;
		Card tempcard;
		int stackchoice;
		for(int i = 0; i < 20; i++)
		{
			do
			{
				stackchoice = (rand() % 2) + 1;
				if(stackchoice == 1)
				{
					tempstack1.push(deal());
				}
				else
				{
					tempstack2.push(deal());
				}
			}while(!isEmpty());

			do
			{
				stackchoice = (rand() % 2) + 1;
				if((stackchoice == 1 && !tempstack1.isEmpty()) || (stackchoice == 2 && tempstack2.isEmpty()))
        	        	{
					push(tempstack1.pop());
                		}
                		else
				{
					push(tempstack2.pop());
				}
			}while(!tempstack1.isEmpty() || !tempstack2.isEmpty());
		}
  	}
}






















