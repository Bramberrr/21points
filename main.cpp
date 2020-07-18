#include "Game.h"
#include <string>
#include <iostream>
using namespace std;

ostream &operator<<(ostream &os, const Card &aCard);
ostream &operator<<(ostream &os, const GenericPlayer &aGenericPlayer);
int main()
{
  Game aGame;
  int ch = 1;
  ch = aGame.Menu();
  while (ch != -1)
  {
    switch (ch)
    {
    case 0:
      aGame.Continue();
      do
      {
        aGame.Play();
      } while (aGame.JudgePlay());
      aGame.Save();
      break;
    case 1:
      aGame.InitUser();
      do
      {
        aGame.Play();
      } while (aGame.JudgePlay());
      aGame.Save();
      break;
    case 2:
      aGame.InitUsers();
      do
      {
        aGame.Play();
      } while (aGame.JudgePlay());
      aGame.Save();
      break;
    case 3:
      aGame.Help();
      break;
    default:
      exit(0);
    }
    ch = aGame.Menu();
  }

  return 0;
}
