#include "Game.h"

using namespace std;

Game::Game()
{

}

void Game::view() const
{
    cout << "| "
         << left << setw(6)  << this->GameId     << " | "
         << left << setw(30) << this->GameName   << " | "
         << left << setw(18) << this->GameGenre  << " | "
         << left << setw(7)  << this->GameRate << " | "
         << left << setw(10) << this->GamePrice  << " |"
         << endl;
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

string Game::getGenre() const
{
    return this->GameGenre;
}

string Game::getRate() const
{
    return this->GameRate;
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
        cout << "2. GamePrice" << endl;
        cout << "3. GameGenre" << endl;
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
                    cout << "New GamePrice: ";
                    getline(cin, this->GamePrice);
                    cout << "Da doi thanh " << this->GamePrice <<endl;
                    break;
                }
            case 3:
                {
                    cout << "New GameGenre: ";
                    getline(cin, this->GameGenre);
                    cout << "Da doi thanh " << this->GameGenre <<endl;
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

void Game::rate(double rate)
{
    double oldRate = stod(this->GameRate);
    int rateCount = stoi(this->GameRateCount);
    double newRate = (oldRate * rateCount + rate) / (rateCount + 1);
    rateCount++;
    this->GameRate = to_string(newRate);
    this->GameRateCount = to_string(rateCount);
}

void Game::format()
{
    cout << "+--------+--------------------------------+--------------------+---------+------------+\n";
    cout << "| ID     | Game                           | Genre              | Rating  | Price      |\n";
    cout << "+--------+--------------------------------+--------------------+---------+------------+\n";
}

void Game::writeToFile(ofstream& fout)
{
    fout << this->GameId << "," << this->GameName << "," << this->GamePrice << "," << this->GameGenre << "," << this->GameRate << "," << this->GameRateCount << endl;
}

void Game::readFromFile(ifstream& fin)
{
    getline(fin, this->GameId, ',');
    getline(fin, this->GameName, ',');
    getline(fin, this->GamePrice, ',');
    getline(fin, this->GameGenre, ',');
    getline(fin, this->GameRate, ',');
    getline(fin, this->GameRateCount);
}
