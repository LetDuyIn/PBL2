#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Game
{
    friend class User;
protected:
    string GameId;
    string GameName;
    double GamePrice;
public:
    Game(string, string, double);
    void viewGame();
    string getId();
    double getPrice();
};

#endif // GAME_H_INCLUDED
