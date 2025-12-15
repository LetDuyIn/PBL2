#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct countNode
{
    string type;
    int qnt = 0;
    countNode* next = nullptr;
};

class Admin
{
private:
    string AdminId;
    string AdminName;
    string AdminPass;
    countNode* sta = new countNode;
public:
    Admin();

    void create(int);
    void info();
    void view() const;
    void upd();

    string getId() const;
    string getPass() const;
    void format();

    void addGame();
    void revGame();
    void updGame();
    void viewAllGames();

    void cycle(string);
    void clearCycle();
    void popGenre();
    void popGame();
    void showPop();

    void writeToFile(ofstream&);
    void readFromFile(ifstream&);
};

#endif // ADMIN_H_INCLUDED
