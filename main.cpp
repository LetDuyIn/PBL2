#include <iostream>
#include "Game.h"
#include "Cart.h"
#include "User.h"
#include "Ultil.h"

using namespace std;

int main()
{
    HashTable<Game>* GameInStore = new HashTable<Game>(10);
    GameInStore->showAll();

    Game g1("LOL", "G01", "30000");
    Game g2("Skyrim", "G02", "25000");
    Game g3("Dota 2", "G03", "37000");
    Game g4("Mine", "G04", "42000");
    Game g5("Ter", "G05", "15000");

    GameInStore->add(g1);
    GameInStore->add(g2);
    GameInStore->add(g3);
    GameInStore->add(g4);
    GameInStore->add(g5);

    //saveToFile(GameInStore, "GameInStore.txt");

    //loadFromFile(GameInStore, "GameInStore.txt");

    GameInStore->showAll();

    g2.upd();
    g2.view();

    //GameInStore->add(g2);

    GameInStore->showAll();

    delete GameInStore;

}
