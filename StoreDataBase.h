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
    HashTable<Game>* GameInStore = new HashTable(99);
    HashTable<User>* GameInStore = new HashTable(99);
    HashTable<Admin>* GameInStore = new HashTable(99);

private:
    StoreDataBase();
    StoreDataBase(const StoreDataBase&) = delete;
    StoreDataBase& operator=(const StoreDataBase&) = delete;
public:
    ~StoreDataBase();
    static StoreDataBase* Instance();
    void Show();
};

CSDL::CSDL()
{
    cout << "Create" << endl;
}

CSDL::~CSDL(){}

CSDL* CSDL::Instance()
{
    if(_Instance == nullptr)
        _Instance = new CSDL();
    return _Instance;
}

void CSDL::Show()
{
    cout << "Show" << endl;
}

CSDL* CSDL::_Instance = nullptr;

#endif // STOREDATABASE_H_INCLUDED
