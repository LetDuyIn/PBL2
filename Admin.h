#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <string>
#include <iostream>
#include <string>
#include <limits> 
#include "Game.h"
#include "Ultil.h" 
using namespace std;

class Admin
{
private:
    // Con trỏ để giữ kho game
    HashTable<Game>* store; 

    
    void clearInputBuffer(); 

public:
    
    Admin(HashTable<Game>* gameStore); 

    void addGameToStore();    
    void revGameFromStore(); 
    void updGameInStore(); 
};

#endif // ADMIN_H_INCLUDED