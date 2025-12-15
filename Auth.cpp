#include "Auth.h"

#include "Ultil.h"
#include "User.h"
#include "Admin.h"


#include <iostream>
#include <string>

void regAdmin(HashTable<Admin>* admins)
{
    Admin newAdmin;

    int newId = admins->availId();
    newAdmin.create(newId);

    cin.ignore();
    newAdmin.info();

    admins->add(newAdmin, true);

    cout << "Dang ky Admin thanh cong!" << endl;
}

void regUser(HashTable<User>* users)
{
    User newUser;

    int newId = users->availId();
    newUser.create(newId);

    cin.ignore();
    newUser.info();

    users->add(newUser, true);

    cout << "Dang ky User thanh cong!" << endl;
}

User* logUser(HashTable<User>* users)
{
    string id, pass;

    cout << "User ID: ";
    cin >> id;
    cin.ignore();

    User* user = users->findById(id);
    if (!user)
    {
        cout << "User khong ton tai!\n";
        return nullptr;
    }

    cout << "Mat khau: ";
    getline(cin, pass);

    if (user->getPass() != pass)
    {
        cout << "Sai mat khau!\n";
        return nullptr;
    }

    cout << "Dang nhap USER thanh cong!\n";
    return user;
}


Admin* logAdmin(HashTable<Admin>* admins)
{
    string id, pass;

    cout << "Admin ID: ";
    cin >> id;
    cin.ignore();

    Admin* admin = admins->findById(id);
    if (!admin)
    {
        cout << "Admin khong ton tai!\n";
        return nullptr;
    }

    cout << "Mat khau: ";
    getline(cin, pass);

    if (admin->getPass() != pass)
    {
        cout << "Sai mat khau!\n";
        return nullptr;
    }

    cout << "Dang nhap ADMIN thanh cong!\n";
    return admin;
}
