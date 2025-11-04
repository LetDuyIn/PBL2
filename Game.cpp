#include <iostream>
#include "Game.h"

using namespace std;

Game::Game(string name, string id, double price) : GameName(name), GameId(id), GamePrice(price)
{

}

void Game::view() const
{
    cout << "Ten: " << this->GameName << " Id: " << this-> GameId << " Gia: " << this->GamePrice << endl;
}

string Game::getId() const
{
    return this->GameId;
}

double Game::getPrice() const
{
    return this->GamePrice;
}

void Game::writeToFile(ofstream& fout)
{
    fout << this->GameId << ", " << this->GameName << ", " << this->GamePrice <<endl;
}

void Game::readFromFile(ifstream& fin)
{
    string price;

    getline(fin, this->GameId, ',');
    getline(fin, this->GameName, ',');
    getline(fin, price);

    this->GamePrice = stod(price);
}
