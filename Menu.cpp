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
        // Hien thi thong tin ngay lap tuc
        cout << "\n========== THONG TIN CA NHAN ==========\n";
        user->format();
        user->view();
        cout << "=======================================\n";

        cout << "1. Cap nhat thong tin\n";
        cout << "0. Quay lai\n";
        cout << "---------------------------------------\n";
        cout << "Lua chon: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
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
        // Hien thi danh sach game ngay lap tuc
        cout << "\n========== DANH SACH GAME ==========\n";
        gameTable->showAll();
        cout << "====================================\n";

        cout << "1. Loc theo the loai\n";
        cout << "2. Loc theo do hot\n";
        cout << "3. Them game vao cart\n";
        cout << "0. Quay lai\n";
        cout << "------------------------------------\n";
        cout << "Lua chon: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1: // Cu la 2
                user->sortByGenre(gameTable);
                break;
            case 2: // Cu la 3
                user->sortByRate(gameTable);
                break;
            case 3: // Cu la 4
                user->addPerCart(gameTable);
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

void userCartMenu(User* user)
{
    int choice;
    do
    {
        system("cls");
        // Hien thi gio hang ngay lap tuc
        cout << "\n========== GIO HANG CUA BAN ==========\n";
        user->viewPerCart();
        cout << "======================================\n";

        cout << "1. Xoa game khoi cart\n";
        cout << "2. Danh gia game\n";
        cout << "3. Tong tien trong cart\n";
        cout << "0. Quay lai\n";
        cout << "--------------------------------------\n";
        cout << "Lua chon: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1: // Cu la 2
                user->revPerCart();
                break;
            case 2: // Cu la 3
                user->rate();
                break;
            case 3: // Cu la 4
            {
                Cart* myCart = user->getCart();
                double total = myCart->sum();
                cout << ">>> Tong tien thanh toan: " << total << endl;
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
        cout << "-------------------------------\n";
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
                cout << "Dang xuat USER...\n";
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
        // Hien thi danh sach user ngay lap tuc
        cout << "\n========== DANH SACH USER ==========\n";
        admin->viewAllUsers(userList);
        cout << "====================================\n";

        cout << "1. Xoa User (Ban tai khoan)\n";
        cout << "0. Quay lai\n";
        cout << "------------------------------------\n";
        cout << "Lua chon: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1: // Cu la 2
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
        // Hien thi thong tin admin ngay lap tuc
        cout << "\n========== THONG TIN ADMIN ==========\n";
        admin->format();
        admin->view();
        cout << "=====================================\n";

        cout << "1. Cap nhat thong tin\n";
        cout << "0. Quay lai\n";
        cout << "-------------------------------------\n";
        cout << "Lua chon: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1: // Cu la 2
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
        // Hien thi kho game ngay lap tuc
        cout << "\n========== QUAN LY KHO GAME ==========\n";
        admin->viewAllGames(gameList);
        cout << "======================================\n";

        cout << "1. Them Game moi\n";
        cout << "2. Cap nhat Game\n";
        cout << "3. Xoa Game\n";
        cout << "4. Thong ke doanh thu/hot\n";
        cout << "0. Quay lai\n";
        cout << "--------------------------------------\n";
        cout << "Lua chon: ";
        cin >> choice; cin.ignore();

        switch (choice) {
            case 1: // Cu la 2
                admin->addGame(gameList);
                break;
            case 2: // Cu la 3
                admin->updGame(gameList);
                break;
            case 3: // Cu la 4
                admin->revGame(gameList);
                break;
            case 4: // Cu la 5
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
        cout << "--------------------------------\n";
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
                cout << "Dang xuat ADMIN...\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
        if(choice != 0) system("pause");
    } while (choice != 0);
}
