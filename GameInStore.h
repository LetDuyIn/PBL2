#ifndef GAMEINSTORE_H_INCLUDED
#define GAMEINSTORE_H_INCLUDED

#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#include "Game.h"

using namespace std;

struct hashNode
{
    Game g;
    hashNode* next;
    hashNode(const Game&, hashNode*);
};

typedef struct hashNode *Node;

struct hashTableInfo
{
    int cap;
    Node* T;
};

typedef hashTableInfo hashTable;

class GameInStore
{
private:
    hashTable *gameStore;
    int cap;
public:
    GameInStore(int);
    ~GameInStore();
    int hashFunction(string);
    void addGame(Game);
    Game* findById(string);
    void show(string);
    void showAll();
};

#endif // GAMEINSTORE_H_INCLUDED
