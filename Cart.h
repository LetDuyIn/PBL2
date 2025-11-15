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
    HashTable<Game>* gameList;
    int cap;
public:
    Cart();
    ~Cart();
    void addCart(Game);
    void revCart(string);
    void showCart();
    void showGame(string);
    double sum();
};

#endif // CART_H_INCLUDED
