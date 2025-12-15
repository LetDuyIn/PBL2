#include "StoreDataBase.h"

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
