#ifndef ULTIL_H_INCLUDED
#define ULTIL_H_INCLUDED

using namespace std;

template <typename T>
struct Node
{
    T obj;
    Node* next;
    Node(const T& o, Node* n) : obj(o), next(n) {}
};

template <typename T>
struct HashTableInfo
{
    int cap;
    Node<T>** table;

    HashTableInfo(int cap)
    {
        this->cap = cap;
        table = new Node<T>*[this->cap];
        for (int i = 0; i < cap; i++)
            table[i] = nullptr;
    }

    ~HashTableInfo()
    {
        for (int i = 0; i < cap; i++)
        {
            Node<T>* curNode = table[i];
            while (curNode != nullptr)
            {
                Node<T>* temp = curNode;
                curNode = curNode->next;
                delete temp;
            }
        }
        delete[] table;
    }
};

template <typename T>
class HashTable
{
protected:
    HashTableInfo<T>* objList;
    int cap;
    int* checkedId;

public:
    HashTable(int cap);
    ~HashTable();

    int getCap() const;
    HashTableInfo<T>* getObjList();

    int hashFunction(const string&);
    int availId();
    int extractNumId(const string&);

    void add(const T&, bool);
    void addNew();
    void rev(const string&);
    void upd(const string&);

    T* findById(const string&);
    void show(const string&);
    void showAll();
};

template <typename T>
void saveToFile(const HashTable<T>*, const string&);

template <typename T>
void loadFromFile(HashTable<T>*, const string&);

#include "Ultil.tpp"

#endif // ULTIL_H_INCLUDED
