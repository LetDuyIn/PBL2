#include <iostream>
#include "Cart.h"
#include "Ultil.h"

using namespace std;

Cart::Cart()
{

}

Cart ::~Cart()
{
    delete this->gameList;
}

int Cart::getCap()
{
    return this->cap;
}

void Cart::addCart(Game g)
{
    this->gameList->add(g, true);
    cout << "==> Da them game " << g.getId() << " vao gio hang." << endl;
}

void Cart::revCart(string& id)
{
    this->gameList->rev(id);
 }

 void Cart::showCart()
 {
     cout << "Gamelist:" << endl;
     this->gameList->showAll();
 }

double Cart::sum()
{
    double totalSum = 0;
    int cartCap = this->gameList->getCap();
    Node<Game>** table = this->gameList->getObjList()->table;

    for (int i = 0; i < cartCap; i++)
    {
        Node<Game>* curNode = table[i];
        while (curNode != nullptr)
        {
            totalSum += stod(curNode->obj.getPrice());
            curNode = curNode->next;
        }
    }
    return totalSum;
}
HashTable<Game>* Cart::getGameList()
{
    return this->gameList;
}
