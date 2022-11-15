#include<iostream>

using namespace std;

class A{
    int a;
    public:
        void setData(int a){
            this->a = a;           //this refers to the instance object and its function and properties
        }

        void showData(){
            cout << "a = " << a << endl;
        }
};

int main(){
    A obj, *p;
    p = &obj;
    p->setData(2);
    p->showData();
    return 0;
}