#include <iostream>
#include "Cart.h"

using namespace std;

Cart::Cart() : cap(0)
{

}

void Cart::addCart(Game g)
{
    gameList.push_back(g);
    this->cap++;
}

void Cart::showCart()
{
    if(gameList.empty())
    {
        cout << "Rong" <<endl;
    }
    else
    {
        cout << "So luong game: " << this->cap << endl;
        cout << "Game List In Cart: " << endl;
        for(auto& g : gameList) g.view();
        cout << "Sum of Money: " << sum() << " VND\n" << endl;
    }
}

void Cart::showGame(string id)
{
    for(auto& g : gameList)
    {
        if(g.getId() == id) g.view();
    }
}

double Cart::sum()
{
    double sum = 0;
    for(auto& g : gameList)
    {
        double price = stod(g.getPrice());
        sum += price;
    }
}
