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

void User::viewStore(HashTable<Game>* store)
{
    cout << "\n --- Xin Chao" << this->UserName << "--- " << endl;
    cout << "--- Danh sach Game co trong cua hang ---" << endl;

    store->showAll();
}

void User::viewGame(HashTable<Game>* store, string id)
{
    cout << "\n--- " << this->UserName << " Dang xem Game" << id << "---" << endl;

    store->show(id);
}
