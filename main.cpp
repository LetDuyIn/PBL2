#include <iostream>
#include "Game.h"
#include "Cart.h"
#include "User.h"
#include "Ultil.h"
#include "StoreDataBase.h"
using namespace std;

int main()
{
    StoreDataBase* store = StoreDataBase::Instance();
    HashTable<Game>* games = store->getGameTable();
    loadFromFile(games, "GameInStore.txt");
    games->showAll();

    HashTable<User>* users = store->getUserTable();
    loadFromFile(users, "UserInStore.txt");
    users->showAll();

    HashTable<Admin>* admins = store->getAdminTable();
    loadFromFile(admins, "AdminInStore.txt");
    admins->showAll();




}
