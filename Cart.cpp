#include <iostream>
#include "Cart.h"
#include "Ultil.h"

using namespace std;

Cart::Cart() 
{
    this->gameList = new HashTable<Game>(10);
}

Cart ::~Cart()
{
    delete this->gameList;
}

void Cart::addCart(Game g)
{
    this->gameList->add(g, true);
    cout << "==> Da them game " << g.getId() << " vao gio hang." << endl;
}

void Cart::showCart()
{
    this->gameList->rev(id);
    cout << "==> Da xoa game " << id << " khoi gio hang." << endl;
}

void Cart::showGame(string id)
{
    // Kiểm tra xem giỏ hàng có rỗng không
    bool empty = true;
    int cartCap = this -> gameList->getCap();
    Node<Game>** table = this -> gameList->getObjList()->table;

    for (int i = 0; i < cartCap; i++)
    {
        if (table[i] != nullptr)
        {
            empty = false;
            break;
        }
    }
    if (empty)
    {
        cout << "Gio hang rong" << endl;
    }
    else
    {
        cout << "Game List In Cart: " << endl;
        // Gọi showAll() của HashTable
        this->gameList->showAll();
        cout <<"Tong tien: " << sum() << "VND\n" << endl;
    }
}

void Cart::revCart(string)
{
    // Gọi hàm show() của HashTable
    cout << "Kiem tra game " << id << "trong gio: " <<endl;
    this->gameList->show(id);
 }

double Cart::sum()
{
    double totalSum = 0;
    int cartCap = this->gameList->getCap();
    Node<Game>** table = this->getObjList()->table;
    // Phải duyệt qua TOÀN BỘ hash table, giống logic của showAll()

    for (int i = 0; i < cartCap; i++)
    {
        Nodde<Game>* curNode = table[i];
        while (curNode != nullpr)
        {
            // Lấy giá (string), chuyển sang double (stod) và cộng vào
            totalSum += stod(curNode->obj.getPrice());
            curNode = curNode->next;
        }
    }
    return totalSum;
}
