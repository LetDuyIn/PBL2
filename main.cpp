#include <iostream>
#include "Game.h"
#include "Cart.h"
#include "User.h"
#include "Ultil.h"
#include "StoreDataBase.h"

using namespace std;

int main()
{
    StoreDataBase* Store = StoreDataBase::Instance();
    loadFromFile(Store->getGameTable(), "GameInStore.txt");
    Store->getGameTable()->showAll();
    Store->getGameTable()->addNew();
    Store->getGameTable()->showAll();
    Store->getGameTable()->
}
