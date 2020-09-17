#ifndef DISCARDPILE_H
#define DISCARDPILE_H
#include <cstdlib>
#include "card.h"

class DiscardPile : public Stack<Card>
{
	public:
		void pileInput(Card inputCard);
		Card topCard();
};

//***************************************
// Function : pileInput
// Input: none
// output: none
// Description: checks to see if a card is an 8, if it is, randomizes suit before placing it in
//*****************************************

void DiscardPile::pileInput(Card inputCard)
{
	if(inputCard.getRank() == 8)
	{
		int suitChange = rand() % 4 + 1;
		if(suitChange == 1)
		{
			inputCard.setSuit(CLUBS);
		}
		if(suitChange == 2)
		{
			inputCard.setSuit(DIAMONDS);
		}
		if(suitChange == 3)
		{
			inputCard.setSuit(HEARTS);
		}
		if(suitChange == 4)
		{
			inputCard.setSuit(SPADES);
		}

		push(inputCard);
	}
	else
	{
		push(inputCard);
	}
}

#endif
