#ifndef PLAYINGHAND_H
#define PLAYINGHAND_H

#include "card.h"

class PlayingHand : public LinkedList<Card>
{
	public:
		PlayingHand();
		void printList();	
};

//***************************************
// Function : PlayingHand
// Input: none
// output: none
// Description: builds playinghand constructor
//*****************************************

PlayingHand::PlayingHand()
{

}

//***************************************
// Function : printList
// Input: none
// output: none
// Description: modified printlist to account for card objects
//*****************************************

void PlayingHand::printList()
{
	Node<Card>* newNode = frontNodePtr;
	int counter = 1;
  	while (newNode != NULL)
 	{
		Card printCard;
    		printCard = newNode->getItem();
		cout<<counter<<". "<<printCard.toString()<<endl;
    		newNode = newNode->getNextPtr(); 
		++counter;
  	}
}
#endif
