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
    string GamePrice;
public:
    Game();
    Game(string, string, string);
    void view() const;
    string getId() const;
    string getPrice() const;

    void upd();

    void writeToFile(ofstream&);
    void readFromFile(ifstream&);
};

#endif // GAME_H_INCLUDED
