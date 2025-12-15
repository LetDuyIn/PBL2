#include "Admin.h"

#include "User.h"
#include "Cart.h"
#include "Game.h"
#include "StoreDataBase.h"

using namespace std;

Admin::Admin()
{

}

void Admin::create(int numId)
{
    stringstream ss;
    ss<< 'A' << setw(2) << setfill('0') << numId;
    this->AdminId = ss.str();
}

void Admin::info()
{
    cout << "Nhap ten: ";
    getline(cin, this->AdminName);
    cout << "Nhap pass: ";
    getline(cin, this->AdminPass);
}

void Admin::view() const
{
    cout << "| "
         << left << setw(6)  << this->AdminId     << " | "
         << left << setw(30) << this->AdminName   << " | "
         << left << setw(18) << this->AdminPass  << " | "
         << endl;
}

void Admin::format()
{
    cout << "+--------+--------------------------------+--------------------+\n";
    cout << "| ID     | Admin                          | AdminPass          |\n";
    cout << "+--------+--------------------------------+--------------------+\n";
}

void Admin::upd()
{
    int choice;
    do
    {
        cout << "Phan can update" << endl;
        cout << "1. AdminName" << endl;
        cout << "2. Dung update" << endl;

        cin >> choice;  cin.ignore();

        switch(choice)
        {
            case 1:
                {
                    cout << "New AdminName: ";
                    getline(cin, this->AdminName);
                    cout << "Da doi thanh " << this->AdminName <<endl;
                    break;
                }
            case 2:
                cout << "Dung update" << endl;
                break;
            default:
                cout << "Chon lai" << endl;
                break;
        }
    } while (choice != 2);
}

string Admin::getId() const
{
    return this->AdminId;
}

string Admin::getPass() const
{
    return this->AdminPass;
}

void Admin::addGame()
{
    StoreDataBase::Instance()->getGameTable()->addNew();
}

void Admin::revGame()
{
    string id;
    cout << "Id game can xoa: "; cin >> id;
    StoreDataBase::Instance()->getGameTable()->rev(id);
}

void Admin::updGame()
{
    string id;
    cout << "Id game can cap nhat: "; cin >> id;
    StoreDataBase::Instance()->getGameTable()->upd(id);
}

void Admin::viewAllGames()
{
    StoreDataBase::Instance()->getGameTable()->showAll();
}

void Admin::cycle(string type)
{
    int found = 0;
    countNode* curNode = this->sta;
    while(curNode->next != nullptr)
    {
        curNode = curNode->next;
        if(curNode->type == type)
        {
            curNode->qnt++;
            found = 1;
            break;
        }
    }

    if(found == 1) return;

    countNode* newNode = new countNode;
    curNode->next = newNode;
    newNode->type = type;
    newNode->qnt++;
}

void Admin::clearCycle()
{
    countNode* curNode = this->sta->next;
    while(curNode != nullptr)
    {
        countNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
    this->sta->next = nullptr;
}

void Admin::popGenre()
{
    clearCycle();
    HashTableInfo<User>* userList = StoreDataBase::Instance()->getUserTable()->getObjList();

    for(int i = 0; i < userList->cap; i++)
    {
        Node<User>* uNode = userList->table[i];

        while(uNode != nullptr)
        {
            User* user = &(uNode->obj);
            Cart* cart = user->getCart();

            HashTableInfo<Game>* gameList = cart->getGameList()->getObjList();

            for(int j = 0; j < gameList->cap; j++)
            {
                Node<Game>* gNode = gameList->table[j];

                while(gNode != nullptr)
                {
                    Game* game = &(gNode->obj);
                    cycle(game->getGenre());

                    gNode = gNode->next;
                }
            }
            uNode = uNode->next;
        }
    }
}

void Admin::popGame()
{
    clearCycle();
    HashTableInfo<User>* userList = StoreDataBase::Instance()->getUserTable()->getObjList();

    for(int i = 0; i < userList->cap; i++)
    {
        Node<User>* uNode = userList->table[i];

        while(uNode != nullptr)
        {
            User* user = &(uNode->obj);
            Cart* cart = user->getCart();

            HashTableInfo<Game>* gameList = cart->getGameList()->getObjList();

            for(int j = 0; j < gameList->cap; j++)
            {
                Node<Game>* gNode = gameList->table[j];

                while(gNode != nullptr)
                {
                    Game* game = &(gNode->obj);
                    cycle(game->getName());

                    gNode = gNode->next;
                }
            }
            uNode = uNode->next;
        }
    }
}

void Admin::showPop()
{
    countNode* curNode = this->sta;
    cout << "----------Thong ke cua hang----------" << endl;

    cout << "Game hot" << endl;
    popGame();
    while(curNode->next != nullptr)
    {
        curNode = curNode->next;
        cout << curNode->type << ": " << curNode->qnt << endl;
    }

    cout << "The loai hot" << endl;
    popGame();
    while(curNode->next != nullptr)
    {
        curNode = curNode->next;
        cout << curNode->type << ": " << curNode->qnt << endl;
    }
}

void Admin::writeToFile(ofstream& fout)
{
    fout << this->AdminId << "," << this->AdminName << "," << this->AdminPass << endl;
}

void Admin::readFromFile(ifstream& fin)
{
    getline(fin, this->AdminId, ',');
    getline(fin, this->AdminName, ',');
    getline(fin, this->AdminPass);
}
