#include "User.h"

using namespace std;

User::User()
{

}

User::~User()
{
    if(this->PerCart != nullptr)
    {
        delete this->PerCart;
        this->PerCart = nullptr;
    }
}

void User::create(int numId)
{
    stringstream ss;
    ss << 'U' << setw(2) << setfill('0') << numId;
    this->UserId = ss.str();
}

void User::info()
{
    cout << "Nhap ten: ";
    getline (cin, this->UserName);
    cout << "Nhap pass: ";
    getline(cin, this->UserPass);
}

void User::view() const
{
    cout << "| "
         << left << setw(6)  << this->UserId     << " | "
         << left << setw(30) << this->UserName   << " | "
         << left << setw(18) << this->UserPass  << " | "
         << endl;
}

void User::upd()
{
    int choice;
    do
    {
        cout << "\n--- CAP NHAT THONG TIN ---\n";
        cout << "1. Doi ten hien thi\n";
        cout << "2. Doi mat khau\n";
        cout << "0. Quay lai\n";
        cout << "Lua chon: ";
        cin >> choice; cin.ignore();

        switch(choice)
        {
        case 1:
            {
                cout << "Nhap ten moi: "; getline(cin, this->UserName);
                break;
            }
        case 2:
            {
                cout << "Nhap mat khau moi: "; getline(cin, this->UserPass);
                break;
            }
        case 0:
            break;
        default:
            cout << "Chon lai\n";
        }
    }while(choice != 0);
}

void User::viewGameList()
{
    StoreDataBase::Instance()->getGameTable()->showAll();
}

void User::sortByGenre(HashTable<Game>* gameList)
{
    string genre;
    cout << "Nhap the loai: "; cin >> genre;
    for(int i = 0; i < gameList->getCap(); i++)
    {
        Node<Game>* curNode = gameList->getObjList()->table[i];
        if(i == 0) curNode->obj.format();
        while(curNode != nullptr)
        {
            if(curNode->obj.getGenre() == genre)
            {
                curNode->obj.view();
            }
            curNode = curNode->next;
        }
    }
}

void User::sortByRate(HashTable<Game>* gameList)
{
    Node<Game>* sortHead = nullptr;
    for(int i = 0; i < gameList->getCap(); i++)
    {
        Node<Game>* curNode = gameList->getObjList()->table[i];
        if(i == 0) curNode->obj.format();
        while(curNode != nullptr)
        {
            Node<Game>* newNode = new Node<Game>(curNode->obj, nullptr);

            if(sortHead == nullptr || stod(newNode->obj.getRate()) > stod(sortHead->obj.getRate()))
            {
                newNode->next = sortHead;
                sortHead = newNode;
            }
            else
            {
                Node<Game>* p = sortHead;
                while(p->next != nullptr && stod(p->next->obj.getRate()) > stod(newNode->obj.getRate()))
                    p = p->next;
                newNode->next = p->next;
                p->next = newNode;
            }
            curNode = curNode->next;
        }
    }

    Node<Game>* curNode = sortHead;
    while(curNode)
    {
        curNode->obj.view();
        curNode = curNode->next;
    }

    while(sortHead != nullptr)
    {
        Node<Game>* temp = sortHead;
        sortHead = sortHead->next;
        delete temp;
    }
}

void User:: viewPerCart()
{
    this->PerCart->getGameList()->showAll();
}

void User::addPerCart(HashTable<Game>* gameList)
{
    string id;
    cout << "Nhap id: ";
    cin >> id;
    Game* game = gameList->findById(id);
    this->PerCart->gameList->add(*game, true);
}

void User::format()
{
    cout << "+--------+--------------------------------+--------------------+\n";
    cout << "| ID     | User                           | UserPass           |\n";
    cout << "+--------+--------------------------------+--------------------+\n";
}

void User::revPerCart()
{
    string id;
    cout << "Nhap id: ";
    cin >> id;
    this->PerCart->gameList->rev(id);
}

void User::rate()
{
    string id;
    cout << "Nhap id: ";
    cin >> id;

    double rate;
    cout << "Danh gia: ";
    cin >> rate;

    this->PerCart->gameList->findById(id)->rate(rate);

}

string User::getId() const
{
    return this->UserId;
}

string User::getPass() const
{
    return this->UserPass;
}

Cart* User::getCart()
{
    return this->PerCart;
}

void User::writeToFile(ofstream& fout)
{
    fout << this->UserId << "," << this->UserName << "," << this->UserPass << ",";

    HashTable<Game>* gl = this->PerCart->getGameList();

    for(int i = 0; i < gl->getCap(); i++)
    {
        Node<Game>* cur = gl->getObjList()->table[i];
        while(cur != nullptr)
        {
            fout << cur->obj.getId() << "|" << cur->obj.getName() << ",";
            cur = cur->next;
        }
    }
    fout << endl;
}

void User::readFromFile(ifstream& fin)
{
    string line;
    getline(fin, line);

    size_t pos = 0;
    size_t commaPos = line.find(',');
    this->UserId = line.substr(0, commaPos);
    pos = commaPos + 1;

    commaPos = line.find(',', pos);
    this->UserName = line.substr(pos, commaPos - pos);
    pos = commaPos + 1;

    commaPos = line.find(',', pos);
    this->UserPass = line.substr(pos, commaPos - pos);
    pos = commaPos + 1;

    HashTable<Game>* gl = this->PerCart->getGameList();

    while (pos < line.size())
    {
        commaPos = line.find(',', pos);
        if (commaPos == string::npos) commaPos = line.size();

        string token = line.substr(pos, commaPos - pos);
        pos = commaPos + 1;

        size_t pipePos = token.find('|');
        string id = token.substr(0, pipePos);
        string name = token.substr(pipePos + 1);

        Game* g = StoreDataBase::Instance()->getGameTable()->findById(id);
        if (g != nullptr && g->getName() == name)
            gl->add(*g, true);
    }
}


