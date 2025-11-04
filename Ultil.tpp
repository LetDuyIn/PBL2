#include <sstream>
#include <iomanip>

#pragma once

using namespace std;

template <typename T>
HashTable<T>::HashTable(int cap)
{
    this->cap = cap;
    objList = new HashTableInfo<T>(this->cap);
}

template <typename T>
HashTable<T>::~HashTable()
{
    delete objList;
}

template <typename T>
int HashTable<T>::getCap() const
{

    return this->cap;
}

template <typename T>
HashTableInfo<T>* HashTable<T>::getObjList()
{
    return this->objList;
}

template <typename T>
int HashTable<T>::hashFunction(const string& id)
{
    int hashId = 0;
    for (char c : id)
        hashId = hashId * 31 + c;
    return hashId % cap;
}

template <typename T>
void HashTable<T>::add(const T& obj)
{
    int index = hashFunction(obj.getId());
    Node<T>* newNode = new Node<T>(obj, nullptr);
    if(this->objList->table[index] == nullptr)
        this->objList->table[index] = newNode;
    else
    {
        Node<T>* curNode = this->objList->table[index];
        while(curNode->next != nullptr)
            curNode = curNode->next;
        curNode->next = newNode;
    }
}

template <typename T>
T* HashTable<T>::findById(const string& id)
{
    int index = hashFunction(id);
    Node<T>* curNode = this->objList->table[index];
    while(curNode != nullptr)
    {
        if(curNode->obj.getId() == id)
            return &(curNode->obj);
        curNode = curNode->next;
    }
    return nullptr;
}

template <typename T>
void HashTable<T>::show(const string& id)
{
    T* found = findById(id);
    if(found != nullptr)
    {
        found->view();
    }
    else cout << "Ko ton tai " << id << endl;
}

template <typename T>
void HashTable<T>::showAll()
{
    string id;
    for(int i = 0; i < this->cap; i++)
    {
        stringstream ssid;
        ssid << 'G' << setw(2) << setfill('0') << i;
        id = ssid.str();
        show(id);
    }
}

template <typename T>
void saveToFile(HashTable<T>* objList, const string& file)
{
    ofstream fout(file);
     for (int i = 0; i < objList.getCap(); ++i)
    {
        Node<T>* cur = objList.getObjList()->table[i];
        while (cur != nullptr)
        {
            cur->obj.writeToFile(fout);
            cur = cur->next;
        }
    }

    fout.close();
}

template <typename T>
void loadFromFile(HashTable<T>* table, const string& filename)
{
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Không thể mở file để đọc: " << filename << endl;
        return;
    }

    while (!fin.eof()) {
        T obj;
        obj.readFromFile(fin);
        if (!fin.eof())
            table.add(obj);
    }

    fin.close();
}
