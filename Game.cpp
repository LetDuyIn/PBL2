#include <iostream>
#include "Game.h"

using namespace std;

Game::Game(string name, string id, double price) : GameName(name), GameId(id), GamePrice(price)
{

}

void Game::viewGame()
{
    cout << "Ten: " << this->GameName << " Id: " << this-> GameId << " Gia: " << this->GamePrice << endl;
}

string Game::getId()
{
    return this->GameId;
}

double Game::getPrice()
{
    return this->GamePrice;
}
