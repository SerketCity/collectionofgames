#ifndef DECK_H
#define DECK_H

#include "stack.h"
#include "card.h"
#include <time.h>
#include <math.h>
#include <cstdlib>

class Deck : public Stack<Card>
{
   public:
    Deck();
    Card deal();
    void shuffle();
};

#endif
