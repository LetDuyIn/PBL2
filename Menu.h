#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

class User;
class Game;

template<class T>
class HashTable;

void userMenu(User* user, HashTable<Game>* gameTable);
void userInfoMenu(User* user);
void storeGameMenu(User* user, HashTable<Game>* gameTable);
void cartMenu(User* user);





#endif // MENU_H_INCLUDED
