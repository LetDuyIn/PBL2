#include <iostream>
#include "Game.h"
#include "Cart.h"
#include "User.h"
#include "Ultil.h"
#include "StoreDataBase.h"
#pragma once
using namespace std;

int main()
{
    StoreDataBase* Store = StoreDataBase::Instance();
    loadFromFile(Store->getGameTable(), "GameInStore.txt");
    int choice;
    do
    {
        cout << "The Store" << endl;
        cout << "Chuc nang" << endl;
        cout << "1. Xem danh sach game" << endl;
        cout << "2. Leave da store" << endl;

        cin >> choice;  cin.ignore();

        switch(choice)
        {
            case 1:
                {
                    int choice1;

                    do
                    {
                        Store->getGameTable()->showAll();
                        cout << endl;
                        cout << "1. Them" << endl;
                        cout << "2. Xoa"  << endl;
                        cout << "3. Sua"  << endl;
                        cout << "4. Back" << endl;
                        cin >> choice1; cin.ignore();

                        switch(choice1)
                        {
                            case 1:
                                {
                                    Store->getGameTable()->addNew();
                                    break;
                                }
                            case 2:
                                {
                                    string id;
                                    cout << "Nhap Id can xoa"; cin >> id;
                                    Store->getGameTable()->rev(id);
                                    break;
                                }
                            case 3:
                                {
                                    string id;
                                    cout << "Nhap Id "; cin >> id;
                                    Store->getGameTable()->upd(id);
                                    break;
                                }
                            case 4:
                                {
                                    break;
                                }
                        }
                    } while(choice1 != 4);

                }
            case 2:
                {
                    break;
                }

        }
    } while(choice != 2);
}
