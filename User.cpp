#include <iostream>
#include "User.h"

using namespace std;

User::User(string name, string id, Cart cart) : UserName(name), UserId(id), PerCart(cart)
{

}

void User::viewPerCart()
{
    cout << "Gio hang cua khach hang " << this->UserName << endl;
    this->PerCart.showCart();
}

void User::viewStore(GameInStore Store)
{
    Store.showAll();
}

void User::viewGame(string id)
{

}
