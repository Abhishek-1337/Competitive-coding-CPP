#include <bits/stdc++.h>
using namespace std;

struct myHash
{
    int BUCKET;
    list<int> *table;

    myHash(int b)
    {
        BUCKET = b;
        table = new list<int>[BUCKET];
    }
    int hashFn(int key)
    {
        return key % BUCKET;
    }

    void insert(int key)
    {
        int i = hashFn(key);
        table[i].push_back(key);
    }

    void remove(int key)
    {
        int i = hashFn(key);
        table[i].remove(key);
    }

    void search(int key)
    {
        int i = hashFn(key);
        for (auto it : table[i])
        {
            if (key == it)
            {
                cout << "true";
                return;
            }
        }
        cout << "false";
        cout << endl;
    }
};

int main()
{
    myHash hash(10);
    hash.insert(50);
    hash.insert(21);
    hash.insert(58);
    hash.insert(17);
    hash.insert(15);
    hash.insert(49);
    hash.insert(56);
    hash.insert(22);
    hash.insert(23);
    hash.insert(25);

    hash.search(28);
    return 0;
}