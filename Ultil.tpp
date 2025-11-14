#include <sstream>
#include <iomanip>

#pragma once

using namespace std;

template <typename T>
HashTable<T>::HashTable(int cap)
{
    this->cap = cap;
    this->qnt = 0;
    objList = new HashTableInfo<T>(this->cap);

    checkedId = new int[cap + 1];
    for(int i = 0; i <= cap; i++)
        checkedId[i] = 0;
}

template <typename T>
int HashTable<T>::availId()
{
    for(int i = 1; i <= this->cap; i++)
    {
        if(this->checkedId[i] == 0)
            return i;
    }
}

template <typename T>
int HashTable<T>::extractNumId(const string& id)
{
    int pos = 0;
    while(pos < id.size() && !isdigit(id[pos]))
        pos++;
    return stoi(id.substr(pos));
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
void HashTable<T>::add(const T& obj, bool file)
{
    T newObj = obj;
    int numId;

    if(!file)
    {
        numId = availId();
        newObj.create(numId);
    }
    else numId = extractNumId(newObj.getId());

    int index = hashFunction(newObj.getId());
    Node<T>* newNode = new Node<T>(newObj, nullptr);
    if(this->objList->table[index] == nullptr)
        this->objList->table[index] = newNode;
    else
    {
        Node<T>* curNode = this->objList->table[index];
        while(curNode->next != nullptr)
            curNode = curNode->next;
        curNode->next = newNode;
    }
    this->checkedId[numId] = true;
}

template <typename T>
void HashTable<T>::addNew()
{
    T obj;
    int numId = availId();

    obj.create(numId);
    obj.info();
    add(obj, false);
}

template <typename T>
void HashTable<T>::rev(const string& id)
{
    int index = hashFunction(id);
    Node<T>* curNode = this->objList->table[index];
    Node<T>* prevNode = nullptr;
    while(curNode != nullptr)
    {
        if(curNode->obj.getId() == id)
        {
            if(prevNode == nullptr)
                this->objList->table[index] = curNode->next;
            else prevNode->next = curNode->next;

            delete curNode;
            curNode = nullptr;

            int numId = extractNumId(id);
            this->checkedId[numId] = false;
            break;
        }
        prevNode = curNode;
        curNode = curNode->next;
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
    if (found != nullptr)
        found->view();
}

template <typename T>
void HashTable<T>::upd(const string& id)
{
    T* found = findById(id);
    if(found == nullptr)
    {
        cout << "Ko tim thay Id de update" << endl;
        return;
    }
    found->upd();
}

template <typename T>
void HashTable<T>::showAll()
{
    for (int i = 0; i < this->cap; i++)
    {
        Node<T>* curNode = this->objList->table[i];
        while (curNode != nullptr)
        {
            curNode->obj.view();
            curNode = curNode->next;
        }
    }
}

template <typename T>
void saveToFile(HashTable<T>* objList, const string& file)
{
    ofstream fout(file);

    if (!fout.is_open())
    {
        cerr << "Ko mo dc file: " << file << endl;
        return;
    }

    for (int i = 0; i < objList->getCap(); ++i)
    {
        Node<T>* cur = objList->getObjList()->table[i];
        while (cur != nullptr)
        {
            cur->obj.writeToFile(fout);
            cur = cur->next;
        }
    }

    fout.close();
}

template <typename T>
void loadFromFile(HashTable<T>* objList, const string& filename)
{
    ifstream fin(filename);
    if(!fin.is_open())
    {
        cerr << "Ko mo dc file: " << filename << endl;
        return;
    }

    int loadQnt = 0;
    while(!fin.eof())
    {
        T obj;
        obj.readFromFile(fin);
        if (fin.fail())
            break;
        objList->add(obj, true);
    }
    fin.close();
}
