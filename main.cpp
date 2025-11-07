#include <iostream>
#include "Game.h"
#include "Cart.h"
#include "User.h"
#include "Ultil.h"
#include "StoreDataBase.h"

using namespace std;

int main()
{
    HashTable<Game>* GameInStore = new HashTable<Game>(10);
    GameInStore->showAll();

    GameInStore->addNew();
    GameInStore->addNew();
    GameInStore->addNew();

    //GameInStore->add();

    //saveToFile(GameInStore, "GameInStore.txt");

    //loadFromFile(GameInStore, "GameInStore.txt");

    GameInStore->showAll();
    GameInStore->rev("G02");
    GameInStore->showAll();


    //GameInStore->add(g2);

    //GameInStore->showAll();

    delete GameInStore;

}
