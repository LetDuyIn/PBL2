#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#pragma once

#include "User.h"
#include "Cart.h"
#include "Game.h"
#include "Ultil.h"

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

    void addGame(HashTable<Game>*);
    void revGame(HashTable<Game>*);
    void updGame(HashTable<Game>*);
    void viewAllGames(HashTable<Game>*);

    void viewAllUsers(HashTable<User>*);
    void revUser(HashTable<User>*);

    void cycle(string);
    void clearCycle();
    void popGenre(HashTable<User>*);
    void popGame(HashTable<User>*);
    void showPop(HashTable<User>*);

    void writeToFile(ofstream&);
    void readFromFile(ifstream&);
};

#endif // ADMIN_H_INCLUDED
