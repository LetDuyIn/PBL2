#ifndef STOREDATABASE_H_INCLUDED
#define STOREDATABASE_H_INCLUDED

#include <iostream>

#include "Game.h"
#include "Ultil.h"

class Admin;
class User;

using namespace std;
class StoreDataBase
{
private:
    static StoreDataBase* _Instance;
    HashTable<Game>* GameInStore = new HashTable<Game>(100);
    HashTable<User>* UserInStore = new HashTable<User>(100);
    HashTable<Admin>* AdminInStore = new HashTable<Admin>(100);

private:
    StoreDataBase();
    StoreDataBase(const StoreDataBase&) = delete;
    StoreDataBase& operator=(const StoreDataBase&) = delete;
public:
    HashTable<Game>* getGameTable();
    HashTable<User>* getUserTable();
    HashTable<Admin>* getAdminTable();

    User* findUser(string);
    void addUser();

    Admin* findAdmin(string);
    void addAdmin();

    ~StoreDataBase();
    static StoreDataBase* Instance();
};


#endif // STOREDATABASE_H_INCLUDED
