#ifndef CART_H_INCLUDED
#define CART_H_INCLUDED

#pragma once
#include "Game.h"
#include "Ultil.h"

using namespace std;

class Cart
{
    friend class User;
protected:
    HashTable<Game>* gameList = new HashTable<Game>(100);
    int cap;
public:
    Cart();
    ~Cart();

    void addCart(Game);
    void revCart(string&);
    void showCart();
    double sum();

    HashTable<Game>* getGameList();
};

#endif // CART_H_INCLUDED
