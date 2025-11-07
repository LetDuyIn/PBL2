#include "Admin.h"

// Hàm khởi tạo: Gán con trỏ 'store' bằng địa chỉ kho game được truyền vào
Admin::Admin(HashTable<Game>* gameStore) : store(gameStore)
{
    // this->store = gameStore; // (Đây là cách viết tường minh)
}

// Hàm tiện ích (để xóa bộ đệm cin)
void Admin::clearInputBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Chức năng THÊM GAME
void Admin::addGameToStore()
{
    string id, name, price;
    cout << "\n--- THEM GAME MOI ---" << endl;
    
    cout << "Nhap ID game (vi du: G06): ";
    cin >> id;
    clearInputBuffer(); // Quan trọng

    cout << "Nhap Ten game: ";
    getline(cin, name); // Dùng getline để nhập tên có khoảng trắng

    cout << "Nhap Gia game: ";
    cin >> price;
    clearInputBuffer(); // Quan trọng

    // Tạo game mới
    Game newGame(name, id, price);
    
    // Dùng con trỏ 'store' để gọi hàm add() từ Ultil.h
    store->add(newGame);

    cout << "==> Da them game '" << name << "' vao kho." << endl;
}

// Chức năng XÓA GAME
void Admin::removeGameFromStore()
{
    string id;
    cout << "\n--- XOA GAME ---" << endl;
    cout << "Nhap ID game can xoa: ";
    cin >> id;

    // Dùng con trỏ 'store' để gọi hàm rev() từ Ultil.h
    store->rev(id);
    
    cout << "==> Da gui yeu cau xoa game " << id << "." << endl;
    cout << "(Luu y: Kiem tra lai danh sach de chac chan game da bi xoa)" << endl;
}

// Chức năng CẬP NHẬT GAME
void Admin::updateGameInStore()
{
    string id;
    cout << "\n--- CAP NHAT GAME ---" << endl;
    cout << "Nhap ID game can cap nhat: ";
    cin >> id;

    // 1. Tìm game trong kho
    Game* gameToUpdate = store->findById(id);

    // 2. Kiem tra xem co tim thay khong
    if (gameToUpdate != nullptr)
    {
        cout << "Tim thay game: " << gameToUpdate->getId() << endl;
        // 3. Gọi hàm upd() của chính game đó
        // (Hàm này đã được viết sẵn trong Game.cpp)
        gameToUpdate->upd();
        cout << "==> Da cap nhat game " << id << "." << endl;
    }
    else
    {
        cout << "==> Khong tim thay game voi ID: " << id << endl;
    }
}
