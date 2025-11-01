#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#pragma once
#include <iostream>
#include <fstream>
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
    void view();
    string getId() const;
    double getPrice();

    void writeToFile(ofstream&);
    void readFromFile(ifstream&);
};

#endif // GAME_H_INCLUDED
