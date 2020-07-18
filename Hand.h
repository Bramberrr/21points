#ifndef _HAND_H_
#define _HAND_H_
#include "Card.h"
#include <vector>
using namespace std;
class Hand
{
public:
  Hand();

  virtual ~Hand();
  void Add(Card *pCard);
  void Clear();
  int GetTotal() const;

protected:
  vector<Card *> m_Cards;
};
#endif