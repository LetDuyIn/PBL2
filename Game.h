#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Game
{
    friend class User;
protected:
    string GameId;
    string GameName;
    string GamePrice;
    string GameGenre;
    string GameRate;
    string GameRateCount;
public:
    Game();

    void create(int);
    void info();
    void view() const;
    void upd();

    void rate(double);
    void format();

    string getId() const;
    string getPrice() const;
    string getName() const;
    string getGenre() const;
    string getRate() const;

    void writeToFile(ofstream&);
    void readFromFile(ifstream&);
};

#endif // GAME_H_INCLUDED
