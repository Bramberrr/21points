#ifndef _DECK_H_
#define _DECK_H_
#include "Hand.h"
#include "GenericPlayer.h"
#include <iostream>
using namespace std;
class Deck : public Hand
{
public:
    Deck();

    virtual ~Deck();
    void Populate();
    void Shuffle();
    void Deal(Hand &aHand);
    void AdditionalCards(GenericPlayer &aGenericPlayer);
};
#endif