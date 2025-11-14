#ifndef STOREDATABASE_H_INCLUDED
#define STOREDATABASE_H_INCLUDED

#include <iostream>
#include "Ultil.h"
#include "Game.h"
#include "User.h"
#include "Admin.h"

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

    ~StoreDataBase();
    static StoreDataBase* Instance();
};

StoreDataBase::StoreDataBase()
{

}

StoreDataBase::~StoreDataBase(){}

StoreDataBase* StoreDataBase::Instance()
{
    if(_Instance == nullptr)
        _Instance = new StoreDataBase();
    return _Instance;
}

HashTable<Game>* StoreDataBase::getGameTable()
{
    return this->GameInStore;
}

HashTable<User>* StoreDataBase::getUserTable()
{
    return this->UserInStore;
}

HashTable<Admin>* StoreDataBase::getAdminTable()
{
    return this->AdminInStore;
}

StoreDataBase* StoreDataBase::_Instance = nullptr;

#endif // STOREDATABASE_H_INCLUDED
