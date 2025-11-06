#include <iostream>
#include "Game.h"

using namespace std;

Game::Game() : GameName(""), GameId(""), GamePrice("")
{

}

Game::Game(string name, string id, string price) : GameName(name), GameId(id), GamePrice(price)
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

string Game::getPrice() const
{
    return this->GamePrice;
}

void Game::upd()
{
    int choice;
    do
    {
        cout << "Phan can update" << endl;
        cout << "1. GameName" << endl;
        cout << "2. GameId" << endl;
        cout << "3. GamePrice" << endl;
        cout << "4. Dung update" << endl;

        cin >> choice;  cin.ignore();

        switch(choice)
        {
            case 1:
                {
                    string newName;
                    cout << "New GameName: ";
                    getline(cin, newName);
                    this->GameName = newName;
                    cout << "Da doi thanh " << this->GameName <<endl;
                    break;
                }
            case 2:
                {
                    string newId;
                    cout << "New GameId: ";
                    getline(cin, newId);
                    this->GameId = newId;
                    cout << "Da doi thanh " << this->GameId <<endl;
                    break;
                }
            case 3:
                {
                    string newPrice;
                    cout << "New GamePrice: ";
                    getline(cin, newPrice);
                    this->GamePrice = newPrice;
                    cout << "Da doi thanh " << this->GamePrice <<endl;
                    break;
                }
            case 4:
                cout << "Dung update" << endl;
            default:
                cout << "Chon lai" << endl;
                break;
        }
    } while (choice != 4);
}

void Game::writeToFile(ofstream& fout)
{
    fout << this->GameId << "," << this->GameName << "," << this->GamePrice <<endl;
    cout << "Saved: " << this->GameId << endl;
}

void Game::readFromFile(ifstream& fin)
{
    getline(fin, this->GameId, ',');
    getline(fin, this->GameName, ',');
    getline(fin, this->GamePrice);
}
