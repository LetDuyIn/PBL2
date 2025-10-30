#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#pragma once
#include <string>
#include <vector>
#include "Cart.h"
#include "Game.h"
#include "GameInStore.h"

using namespace std;

class User
{
protected:
    string UserName;
    string UserId;
    Cart PerCart;
public:
    User(string, string, Cart);
    void viewStore(GameInStore);
    void viewGameList();
    void viewGame(string);
    void viewPerCart();
};

#endif // USER_H_INCLUDED
