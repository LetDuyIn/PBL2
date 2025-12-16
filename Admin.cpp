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
        cout << "2. AdminPass" << endl;
        cout << "3. Dung update" << endl;

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
                {
                    cout << "New AdminPass: ";
                    getline(cin, this->AdminPass);
                    cout << "Da doi thanh " << this->AdminPass << endl;
                    break;
                }
            case 3:
                cout << "Dung update" << endl;
                break;
            default:
                cout << "Chon lai" << endl;
                break;
        }
    } while (choice != 3);
}

string Admin::getId() const
{
    return this->AdminId;
}

string Admin::getPass() const
{
    return this->AdminPass;
}

void Admin::addGame(HashTable<Game>* gameList)
{
    gameList->addNew();
}

void Admin::revGame(HashTable<Game>* gameList)
{
    string id;
    cout << "Id game can xoa: "; cin >> id;
    gameList->rev(id);
}

void Admin::updGame(HashTable<Game>* gameList)
{
    string id;
    cout << "Id game can cap nhat: "; cin >> id;
    gameList->upd(id);
}

void Admin::viewAllGames(HashTable<Game>* gameList)
{
    gameList->showAll();
}

void Admin::viewAllUsers(HashTable<User>* userList)
{
    userList->showAll();
}

void Admin::revUser(HashTable<User>* userlist)
{
    string id;
    cout << "Nhap id: ";
    userlist->rev(id);
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

void Admin::popGenre(HashTable<User>* userList)
{
    clearCycle();

    for(int i = 0; i < userList->getCap(); i++)
    {
        Node<User>* uNode = userList->getObjList()->table[i];

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

void Admin::popGame(HashTable<User>* userList)
{
    clearCycle();
    userList->getObjList();

    for(int i = 0; i < userList->getCap(); i++)
    {
        Node<User>* uNode = userList->getObjList()->table[i];

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

void Admin::showPop(HashTable<User>* userList)
{
    countNode* curNode = this->sta;
    cout << "----------Thong ke cua hang----------" << endl;

    cout << "Game hot" << endl;
    popGame(userList);
    while(curNode->next != nullptr)
    {
        curNode = curNode->next;
        cout << curNode->type << ": " << curNode->qnt << endl;
    }

    cout << "The loai hot" << endl;
    popGenre(userList);
    curNode = this->sta;
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
