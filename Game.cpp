#include <iostream>
#include "Game.h"
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

Game::Game()
{

}

void Game::view() const
{
    cout << "Id: " << this-> GameId << " Ten: " << this->GameName << " Gia: " << this->GamePrice << endl;
}

string Game::getId() const
{
    return this->GameId;
}

string Game::getName() const
{
    return this->GameName;
}

string Game::getPrice() const
{
    return this->GamePrice;
}

void Game::create(int numId)
{
    stringstream ss;
    ss<< 'G' << setw(2) << setfill('0') << numId;
    this->GameId = ss.str();
}

void Game::info()
{
    cout << "Nhap ten: ";
    getline(cin, this->GameName);
    cout << "Nhap gia: ";
    getline(cin, this->GamePrice);
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
                    cout << "New GameName: ";
                    getline(cin, this->GameName);
                    cout << "Da doi thanh " << this->GameName <<endl;
                    break;
                }
            case 2:
                {
                    cout << "New GameId: ";
                    getline(cin, this->GameId);
                    cout << "Da doi thanh " << this->GameId <<endl;
                    break;
                }
            case 3:
                {
                    cout << "New GamePrice: ";
                    getline(cin, this->GamePrice);
                    cout << "Da doi thanh " << this->GamePrice <<endl;
                    break;
                }
            case 4:
                cout << "Dung update" << endl;
                break;
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
