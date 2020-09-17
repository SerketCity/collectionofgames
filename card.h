#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;
//Suit type
enum Suit
{
	CLUBS = 0,
	DIAMONDS,
	HEARTS,
	SPADES
};
//Card class
class Card
{
	public:
		Card();
		Card(int r, Suit s);
		Suit getSuit();
		void setSuit(Suit s);
		int getRank();
		void setRank(int r);
		string toString();

	private:
		Suit cardSuit;
		int cardRank;
};

#endif
