#ifndef _GAME_H_
#define _GAME_H_
#include "Deck.h"
#include "PlayerHouse.h"
#include <string>
#include <vector>
#include <iostream>
#include<windows.h>
#include<time.h>
#include<fstream>
#include<iomanip>
using namespace std;
class Game
{
public:
    Game();
    ~Game();
    
    int Menu(); 
    void Save();
    void Continue();
    void InitUser();
    void InitUsers();
    void Play();
    int JudgePlay();
    void Help();

    Deck m_Deck;
    House m_House;
    Player m_Players[10];

};
#endif
