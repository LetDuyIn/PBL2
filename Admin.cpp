#include "Admin.h"

//  Gán con trỏ 'store' bằng địa chỉ kho game được truyền vào
Admin::Admin(HashTable<Game>* gameStore) : store(gameStore)
{

}

// Hàm tiện ích (để xóa bộ đệm cin)
void Admin::clearInputBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Admin::addGameToStore()
{
    string id, name, price;
    cout << "\n--- THEM GAME MOI ---" << endl;
    
    cout << "Nhap ID game (vi du: G06): ";
    cin >> id;
    clearInputBuffer(); 
    cout << "Nhap Ten game: ";
    getline(cin, name); 

    cout << "Nhap Gia game: ";
    cin >> price;
    clearInputBuffer();

    Game newGame(name, id, price);
    
    store->add(newGame);

    cout << "==> Da them game '" << name << "' vao kho." << endl;
}

void Admin::revGameFromStore()
{
    string id;
    cout << "\n--- XOA GAME ---" << endl;
    cout << "Nhap ID game can xoa: ";
    cin >> id;

   // Dùng con trỏ 'store' để gọi hàm add() từ Ultil.h
    store->rev(id);
    
    cout << "==> Da gui yeu cau xoa game " << id << "." << endl;
    cout << "(Luu y: Kiem tra lai danh sach de chac chan game da bi xoa)" << endl;
}


void Admin::updGameInStore()
{
    string id;
    cout << "\n--- CAP NHAT GAME ---" << endl;
    cout << "Nhap ID game can cap nhat: ";
    cin >> id;

    // Tìm game trong kho
    Game* gameToUpdate = store->findById(id);

    if (gameToUpdate != nullptr)
    {
        cout << "Tim thay game: " << gameToUpdate->getId() << endl;

        // Gọi hàm upd() của chính game đó
        gameToUpdate->upd();
        cout << "==> Da cap nhat game " << id << "." << endl;
    }
    else
    {
        cout << "==> Khong tim thay game voi ID: " << id << endl;
    }
}