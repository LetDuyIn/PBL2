#include "Menu.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void userInfoMenu(User* user)
{
    int choice;

    do
    {
        system("cls");
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
        if(choice != 0) system("pause");
    }
    while (choice != 0);
}

void userGameMenu(User* user, HashTable<Game>* gameTable)
{
    int choice;

    do
    {
        system("cls");
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
                user->addPerCart(gameTable);
                break;
            }

            case 0:
                break;

            default:
                cout << "Lua chon sai!\n";
        }
        if(choice != 0) system("pause");
    }
    while (choice != 0);
}

void userCartMenu(User* user)
{
    int choice;

    do
    {
        system("cls");
        cout << "\n----- GAME TRONG CART -----\n";
        cout << "1. Xem cart\n";
        cout << "2. Xoa game khoi cart\n";
        cout << "3. Danh gia game\n";
        cout << "4. Tong tien trong cart\n";
        cout << "0. Quay lai\n";
        cout << "Lua chon: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                user->viewPerCart();
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

            case 4:
            {
                Cart* myCart = user->getCart();
                double total = myCart->sum();
                cout << "Tong tien thanh toan: " << total << endl;
            }

            case 0:
                break;

            default:
                cout << "Lua chon sai!\n";
        }
        if(choice != 0) system("pause");
    }
    while (choice != 0);
}

void userMenu(User* user, HashTable<Game>* gameTable)
{
    int choice;

    do
    {
        system("cls");
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
                userGameMenu(user, gameTable);
                break;

            case 3:
                userCartMenu(user);
                break;

            case 0:
                cout << "Dang xuat USER\n";
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }
        if(choice != 0) system("pause");
    }
    while (choice != 0);
}

void adminUserMenu(Admin* admin, HashTable<User>* userList)
{
    int choice;
    do
    {
        system("cls");
        cout << "\n========== QUAN LY USER ==========\n";
        cout << "1. Xem danh sach User\n";
        cout << "2. Xoa User (Ban tai khoan)\n";
        cout << "0. Quay lai\n";
        cout << "Lua chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                admin->viewAllUsers(userList);
                break;
            case 2:
                admin->revUser(userList);
                break;
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
        if(choice != 0) system("pause");
    } while (choice != 0);
}

void adminInfoMenu(Admin* admin)
{
    int choice;

    do
    {
        system("cls");
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
                admin->format();
                admin->view();
                break;

            case 2:
                admin->upd();
                break;

            case 0:
                break;

            default:
                cout << "Lua chon sai!\n";
        }
        if(choice != 0) system("pause");
    }
    while (choice != 0);
}

void adminGameMenu(Admin* admin, HashTable<Game>* gameList, HashTable<User>* userList)
{
    int choice;
    do
    {
        system("cls");
        cout << "\n========== QUAN LY KHO GAME ==========\n";
        cout << "1. Xem kho Game\n";
        cout << "2. Them Game moi\n";
        cout << "3. Cap nhat Game\n";
        cout << "4. Xoa Game\n";
        cout << "5. Thong ke doanh thu/hot\n";
        cout << "0. Quay lai\n";
        cout << "Lua chon: ";
        cin >> choice; cin.ignore();

        switch (choice) {
            case 1:
                admin->viewAllGames(gameList);
                break;

            case 2:
                admin->addGame(gameList);
                break;

            case 3:
                admin->updGame(gameList);
                break;

            case 4:
                admin->revGame(gameList);
                break;

            case 5:
                admin->showPop(userList);
                break;

            case 0:
                break;
            default: cout << "Lua chon sai!\n";
        }
        if(choice != 0) system("pause");
    } while (choice != 0);
}

void adminMenu(Admin* admin, HashTable<Game>* games, HashTable<User>* users)
{
    int choice;

    do
    {
        system("cls");
        cout << "\n========== ADMIN MENU ==========\n";
        cout << "1. Quan ly Kho Game\n";
        cout << "2. Quan ly User\n";
        cout << "3. Thong tin Admin\n";
        cout << "0. Dang xuat\n";
        cout << "Lua chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                adminGameMenu(admin, games, users);
                break;

            case 2:
                adminUserMenu(admin, users);
                break;

            case 3:
                adminInfoMenu(admin);
                break;

            case 0:
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }
        if(choice != 0) system("pause");
    } while (choice != 0);
}
