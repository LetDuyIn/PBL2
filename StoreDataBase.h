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
    HashTable<Game>* GameInStore = new HashTable<Game>(99);
    HashTable<User>* UserInStore = new HashTable<User>(99);
    HashTable<Admin>* AdminInStore = new HashTable<Admin>(99);

private:
    StoreDataBase();
    StoreDataBase(const StoreDataBase&) = delete;
    StoreDataBase& operator=(const StoreDataBase&) = delete;
public:
    ~StoreDataBase();
    static StoreDataBase* Instance();
    void Show();
};

StoreDataBase::StoreDataBase()
{
    cout << "Create" << endl;
}

StoreDataBase::~StoreDataBase(){}

StoreDataBase* StoreDataBase::Instance()
{
    if(_Instance == nullptr)
        _Instance = new StoreDataBase();
    return _Instance;
}

void StoreDataBase::Show()
{
    cout << "Show" << endl;
}

StoreDataBase* StoreDataBase::_Instance = nullptr;

#endif // STOREDATABASE_H_INCLUDED
