#include "Menu.h"



#include <iostream>
using namespace std;

void userInfoMenu(User* user)
{
    int choice;

    do
    {
        cout << "\n----- THONG TIN CA NHAN -----\n";
        cout << "1. Xem thong tin\n";
        cout << "2. Cap nhat thong tin\n";
        cout << "0. Quay lai\n";
        cout << "Lua chon: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                user->format();
                user->view();
                break;

            case 2:
                user->upd();
                break;

            case 0:
                break;

            default:
                cout << "Lua chon sai!\n";
        }
    }
    while (choice != 0);
}

void storeGameMenu(User* user, HashTable<Game>* gameTable)
{
    int choice;

    do
    {
        cout << "\n----- GAME TRONG CUA HANG -----\n";
        cout << "1. Xem tat ca game\n";
        cout << "2. Loc theo the loai\n";
        cout << "3. Loc theo do hot\n";
        cout << "4. Them game vao cart\n";
        cout << "0. Quay lai\n";
        cout << "Lua chon: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                gameTable->showAll();
                break;

            case 2:
            {
                user->sortByGenre(gameTable);
                break;
            }

            case 3:
                user->sortByRate(gameTable);
                break;

            case 4:
            {
                user->addToCart(gameTable);
                break;
            }

            case 0:
                break;

            default:
                cout << "Lua chon sai!\n";
        }
    }
    while (choice != 0);
}

void cartMenu(User* user)
{
    int choice;

    do
    {
        cout << "\n----- GAME TRONG CART -----\n";
        cout << "1. Xem cart\n";
        cout << "2. Xoa game khoi cart\n";
        cout << "3. Danh gia game\n";
        cout << "0. Quay lai\n";
        cout << "Lua chon: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                user->viewCart();
                break;

            case 2:
            {
                user->revPerCart();
                break;
            }

            case 3:
            {
                user->rate();
                break;
            }

            case 0:
                break;

            default:
                cout << "Lua chon sai!\n";
        }
    }
    while (choice != 0);
}

void userMenu(User* user, HashTable<Game>* gameTable)
{
    int choice;

    do
    {
        cout << "\n========== USER MENU ==========\n";
        cout << "1. Thong tin ca nhan\n";
        cout << "2. Game trong cua hang\n";
        cout << "3. Game trong cart\n";
        cout << "0. Dang xuat\n";
        cout << "Lua chon: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                userInfoMenu(user);
                break;

            case 2:
                storeGameMenu(user, gameTable);
                break;

            case 3:
                cartMenu(user);
                break;

            case 0:
                cout << "Dang xuat USER\n";
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }
    }
    while (choice != 0);
}
