#ifndef AUTH_H_INCLUDED
#define AUTH_H_INCLUDED

class User;
class Admin;

template<class T>
class HashTable;

void regAdmin(HashTable<Admin>*);
void regUser(HashTable<User>*);

User* logUser(HashTable<User>*);
Admin* logAdmin(HashTable<Admin>*);


#endif // AUTH_H_INCLUDED
