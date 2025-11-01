#include <iostream>
#include "Game.h"
#include "Cart.h"
#include "User.h"
#include "Ultil.h"
using namespace std;

int main()
{
    HashTable<Game> GameInStore(10);
    GameInStore.showAll();

    Game g0("Skyrim", "G00", 30000);
    Game g1("Skyrim", "G01", 30000);
    Game g2("Skyrim", "G02", 30000);
    Game g3("Skyrim", "G03", 30000);

    GameInStore.add(g0);
    GameInStore.add(g1);
    GameInStore.add(g2);
    GameInStore.add(g3);

    GameInStore.showAll();
}
