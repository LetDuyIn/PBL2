#include <iostream>
#include "GameInStore.h"

using namespace std;

hashNode::hashNode(const Game& g, hashNode* next):
    g(g), next(next)
    {

    }

GameInStore::GameInStore(int cap)
{
    this->cap = cap;
    this->gameStore =  new hashTable;
    this->gameStore->T = new Node[this->cap];
    for(int i = 0; i < this->cap; i++)
    {
        gameStore->T[i] = nullptr;
        //gameStore->T[i]->next = nullptr;
    }
    gameStore->cap = this->cap;
}

GameInStore::~GameInStore()
{
    for(int i = 0; i < this->cap; i++)
    {
        Node current = gameStore->T[i];
        while (current != nullptr)
        {
            Node temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] gameStore->T;
    delete gameStore;
}

int GameInStore::hashFunction(string id)
{
    int hashId = 0;
    for(char c : id)
        hashId = hashId * 31 + c;
    return hashId % this->cap;
}

void GameInStore::addGame(Game g)
{
    int index = hashFunction(g.getId());
    Node newNode = new hashNode(g, nullptr);
    newNode->g = g;
    newNode->next = nullptr;
    if(this->gameStore->T[index] == nullptr)
    {
        gameStore->T[index] = newNode;
    }
    else
    {
        Node current = gameStore->T[index];
        while (current->next != nullptr)
            current = current->next;
        current->next = newNode;
    }
}

Game* GameInStore::findById(string id)
{
    int index = hashFunction(id);
    Node curNode = this->gameStore->T[index];
    while(curNode != nullptr)
    {
        if(curNode->g.getId() == id)
            return &(curNode->g);
        curNode = curNode->next;
    }
    return nullptr;
}

void GameInStore::show(string id)
{
    if(findById(id) != nullptr)
    {
        findById(id)->viewGame();
    }
    else cout << "Ko ton tai " << id <<endl;
}

void GameInStore::showAll()
{
    string id;
    for(int i = 0; i<this->cap; i++)
    {
        stringstream ssid;
        ssid << 'G' << setw(2) << setfill('0') << i;
        id = ssid.str();
        show(id);
    }
}
