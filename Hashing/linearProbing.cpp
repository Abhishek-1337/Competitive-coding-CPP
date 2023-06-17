#include <bits/stdc++.h>
using namespace std;

struct myHash
{
    int *table;
    int BUCKET;
    myHash(int size)
    {
        table = new int[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = -1;
        }
        BUCKET = size;
    }

    int hashFn(int key)
    {
        int i = key % BUCKET;
        return i;
    }

    void insert(int key)
    {
        int index = hashFn(key);
        if (table[index] != -1)
        {
            int nextSlot = index;
            while (table[nextSlot] != -1)
            {
                nextSlot = (nextSlot + 1) % BUCKET;
            }
            if (nextSlot == index)
            {
                cout << "Table is already full" << endl;
                return;
            }
        }
        table[index] = key;
    }

    void erase(int key)
    {
        int index = hashFn(key);
        table[index] = -2;
    }

    bool search(int key)
    {
        int index = key % BUCKET;
        if (table[index] == key)
        {
            return true;
        }

        int nextSlot = index;
        while (table[nextSlot] != key)
        {
            nextSlot = (nextSlot + 1) % BUCKET;
        }
        if (nextSlot == index)
            return false;

        return true;
    }

    void display()
    {
        for (int i = 0; i < BUCKET; i++)
        {
            cout << table[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    myHash hs(7);
    hs.insert(49);
    hs.insert(57);
    hs.insert(72);
    // if (hs.search(56) == true)
    //     cout << "YES, 56 is present" << endl;
    // else
    //     cout << "Not present" << endl;
    hs.display();
    hs.erase(57);
    hs.display();
    // if (hs.search(56) == true)
    //     cout << "YES, 56 is present" << endl;
    // else
    //     cout << "Not present" << endl;
    return 0;
}