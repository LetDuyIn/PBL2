#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#pragma once

#include <string>
#include "StoreDataBase.h"
#include "Cart.h"
#include "Game.h"

using namespace std;

class User
{
protected:
    string UserName;
    string UserId;
    string UserPass;
    Cart* PerCart = new Cart();
public:
    User();
    ~User();

    void create(int);
    void info();
    void view() const;
    void upd();

    string getId() const;
    string getPass() const;
    Cart* getCart();

    void format();

    void viewGameList();
    void sortByGenre(HashTable<Game>*);
    void sortByRate(HashTable<Game>*);
    void viewPerCart();
    void addPerCart(HashTable<Game>* gameList);
    void revPerCart();
    void rate();

    void writeToFile(ofstream&);
    void readFromFile(ifstream&);
};

#endif // USER_H_INCLUDED
