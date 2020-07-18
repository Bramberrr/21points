#ifndef _PLAYERHOUSE_H_
#define _PLAYERHOUSE_H_
#include "GenericPlayer.h"
#include <iostream>
using namespace std;
class Player : public GenericPlayer
{
public:
    Player(const string &name = "");

    virtual ~Player();
    virtual bool IsHitting() const;
    void Win() const;
    void Lose() const;
    void Draw() const;

    int m_Money;
    int m_Bet;
};

class House : public GenericPlayer
{
public:
    House(const string &name = "House");
    virtual ~House();
    virtual bool IsHitting() const;
    void FlipFirstCard();
};
#endif