#include <iostream>
#include "Game.h"
#include "Cart.h"
#include "User.h"
#include "GameInStore.h"
using namespace std;

int main()
{
    Game g1("Minecraft", "G01", 200000);
    Game g2("Elden Ring", "G02", 300000);
    Game g3("Mass Effect", "G03", 400000);
    Game g4("Mass Effect 2", "G04", 400000);
    Game g6("Farcry", "G06", 400000);

    g1.viewGame();
    g2.viewGame();

    Cart l;
    l.showCart();
    l.addCart(g1);
    l.showCart();
    l.addCart(g2);
    l.showCart();

    User duy("duy", "KH01", l);
    duy.viewPerCart();


    GameInStore Store(10);
    Store.addGame(g1);
    Store.addGame(g2);
    Store.addGame(g3);
    Store.addGame(g4);
    Store.addGame(g6);
    Store.show("G01");
    Store.show("G02");
    Store.showAll();

    duy.viewStore(Store);
}
