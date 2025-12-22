#include <iostream>
#include "StoreDataBase.h"
#include "Menu.h"
#include "Auth.h"
#include "Ultil.h"
using namespace std;

int main()
{
    StoreDataBase* store = StoreDataBase::Instance();
    HashTable<Game>* games = store->getGameTable();
    loadFromFile(games, "GameInStore.txt");
    //games->showAll();

    HashTable<User>* users = store->getUserTable();
    loadFromFile(users, "UserInStore.txt");
    //users->showAll();

    HashTable<Admin>* admins = store->getAdminTable();
    loadFromFile(admins, "AdminInStore.txt");
    //admins->showAll();

    int choice;
    do {
        cout << "\n=================================\n";
        cout << "   HE THONG QUAN LY MUA BAN GAME \n";
        cout << "=================================\n";
        cout << "1. Dang nhap Admin\n";
        cout << "2. Dang nhap User\n";
        cout << "3. Dang ky User\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "Lua chon: ";
        cin >> choice; cin.ignore();

        switch(choice) {
            case 1:
            {
                Admin* admin = logAdmin(store->getAdminTable());
                if(admin) adminMenu(admin, games, users);
                break;
            }
            case 2:
            {
                User* user = logUser(store->getUserTable());
                if(user) userMenu(user, games);
                break;
            }
            case 3:
                regUser(store->getUserTable());
                break;
            case 0:
                break;
            default: cout << "Lua chon sai!\n";
        }
    } while(choice != 0);

    cout << "Dang luu du lieu va thoat...\n";
    saveToFile(games, "GameInStore.txt");
    saveToFile(users, "UserInStore.txt");
    saveToFile(admins, "AdminInstore.txt");

    return 0;
}
