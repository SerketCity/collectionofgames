#include<iostream>
#include<string>
#include "card.h"
using namespace std;

/****************************************************************
*   STRUCTURE NAME: Card (constructor) 
*
*   constructor for card, builds with rank 0 and suit CLUBS
*                                  
*  
****************************************************************/
Card::Card()
{
	cardRank = 0;
	cardSuit = CLUBS;
}

/****************************************************************
*   STRUCTURE NAME: Card
*
*   builds card object with parameters r for Rank and s for Suit
*  
****************************************************************/

Card::Card(int r, Suit s)
{
	cardRank = r;
	cardSuit = s;
}

/****************************************************************
*   FUNCTION NAME: getSuit
*  Description: returns the Suit
*
*   PARAMETERS: none
*  
*   RETURN VALUES: Suit
*
****************************************************************/
Suit Card::getSuit()
{
	return cardSuit;
}

/****************************************************************
*   FUNCTION NAME: getRank
*  Description: returns the Rank
*
*   PARAMETERS: none
*
*   RETURN VALUES: int
*
****************************************************************/
int Card::getRank()
{
	return cardRank;
}

/****************************************************************
*   FUNCTION NAME: toString
*  Description: returns string object of card name
*
*   PARAMETERS: none
*
*   RETURN VALUES: string
*
****************************************************************/
string Card::toString()
{
	string cardName;
	string Ranks[14] = {"JOKER", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN","KING"};
	
	//tests for joker, catches invalid cards and makes them jokers
	if(cardRank == 0 || cardRank > 14)
	{
		cardName = Ranks[cardRank];
	}
	
	//sets name to rank and appends rest of name
	if(cardRank > 0 && cardRank < 14)
	{
		cardName = Ranks[cardRank];
		cardName.append( " of ");

		switch(cardSuit)
		{
			case CLUBS:
				cardName.append("CLUBS");
				break;
			case DIAMONDS:
				cardName.append("DIAMONDS");
				break;
			case HEARTS:
				cardName.append("HEARTS");
				break;
			case SPADES:
				cardName.append("SPADES");
				break;
			default:
				break;
		}
	}

	return cardName;
}

/****************************************************************
*   FUNCTION NAME: setSuit
*  Description: sets suit
*
*   PARAMETERS: Suit s
*
*   RETURN VALUES: none
*
****************************************************************/
void Card::setSuit(Suit s)
{
	cardSuit = s;
}

/****************************************************************
*   FUNCTION NAME: setRank
*  Description: sets rank
*
*   PARAMETERS: int r
*
*   RETURN VALUES: none
*
****************************************************************/
void Card::setRank(int r)
{
	cardRank = r;
}
