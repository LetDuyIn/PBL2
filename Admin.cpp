#include <iostream>
#include "string"
#include <limits>
#include "Admin.h"
#include "Game.h"

using namespace std;

Admin::Admin()
{
    // Gán con trỏ store của class Admin bằng địa chỉ của kho game
}

// Hàm tiện ích để tránh lỗi trôi lệnh (cin và getline)
void Admin::clearInputBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

