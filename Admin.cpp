#include <iostream>
#include "string"
#include <limits>
#include "Admin.h"
#include "Game.h"

using namespace std;

Admin::Admin(GameInStore* gameStore) : store(gameStore)
{
    // Gán con trỏ store của class Admin bằng địa chỉ của kho game
}

// Hàm tiện ích để tránh lỗi trôi lệnh (cin và getline)
void Admin::clearInputBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void Admin::addGameToStore()
{
    string id, name;
    double price;

    cout << "--- Them Game Moi ---" << endl;
    cout << "Nhap ID game: ";
    cin >> id;
    clearInputBuffer();
    cout << "Nhap Ten game: ";
    getline(cin, name); // Dùng getline để nhập tên có khoảng trắng
    cout << "Nhap Gia game: ";
    while(!(cin >> price)) { // Vòng lặp kiểm tra input
        cout << "Gia khong hop le. Vui long nhap so: ";
        cin.clear();
        clearInputBuffer();
    }
    clearInputBuffer(); // Xóa bộ đệm sau khi nhập giá
    // Tạo game mới và thêm vào kho thông qua con trỏ 'store'
    Game newGame(name, id, price);
    store->addGame(newGame);

    cout << "==> Da them game '" << name << "' vao kho." << endl;
}
void Admin::revGameFromStore()
{
}

void Admin::updGamePrice()
{
}

void Admin::viewAllGames()
{
    
}
void Admin::viewAnalytics()
{
}
