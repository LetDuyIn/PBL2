#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "User.h"
#include "Game.h"
#include "Admin.h"
#include "Ultil.h"

void userMenu(User*, HashTable<Game>*);
void userInfoMenu(User*);
void userStoreGameMenu(User*, HashTable<Game>*);
void userCartMenu(User*);

void adminMenu(Admin*, HashTable<Game>*, HashTable<User>*);
void adminInfoMenu(Admin*);
void adminGameMenu(Admin*, HashTable<Game>*);
void adminUserMenu(Admin*, HashTable<User>*);





#endif // MENU_H_INCLUDED
