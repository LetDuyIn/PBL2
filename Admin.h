#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#pragma once
#include "Game.h"
#include <string>
#include <iostream>

using namespace std;

class Admin
{
private :
    //GameInStore* store; //Con trỏ trỏ tới kho game

    void clearInputBuffer(); // Hàm tiện ích để xóa bộ đệm input

public:
    Admin();

    void addGame();
    void revGame();
    void updGame();
    void viewAllGames(); // xem kho
    void viewAnalytics();//xem thống kê
};

#endif // ADMIN_H_INCLUDED
