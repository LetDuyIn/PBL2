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
    string GameRate;
public:
    Game();

    void create(int);
    void info();
    void view() const;
    void upd();
    void rate(double);

    string getId() const;
    string getPrice() const;
    string getName() const;

    void writeToFile(ofstream&);
    void readFromFile(ifstream&);
};

#endif // GAME_H_INCLUDED
