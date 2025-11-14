#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#pragma once
#include <string>
#include "Cart.h"
#include "Game.h"
#include "Ultil.h"

using namespace std;

class User
{
protected:
    string UserName;
    string UserId;
    Cart PerCart;
public:
    User(string, string, Cart);
    //void viewStore(GameInStore);
    void viewStore(HashTable<Game>* store);
    void viewGame(HashTable<Game>* store, string id);
    void viewPerCart();
};

#endif // USER_H_INCLUDED
#endif // USER_H_INCLUDED
