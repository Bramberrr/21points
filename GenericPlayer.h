#ifndef _GENERICPLAYER_H_
#define _GENERICPLAYER_H_
#include "Hand.h"
#include <string>
using namespace std;
class GenericPlayer : public Hand
{
public:
    friend ostream &operator<<(ostream &os, const GenericPlayer &aGenericPlayer);
    GenericPlayer(const string &name = " ");
    virtual ~GenericPlayer();
    virtual bool IsHitting() const = 0;
    bool IsBusted() const;
    void Bust() const;


    string m_Name;
};
#endif