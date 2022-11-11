#include<iostream>
using namespace std;

class A{
    int a;
    public:
        A(int x){
            a = x;
            cout << "a = " << a << endl;
        }
};

class B:public A{
    int b;
    public:
        B(int x, int y):A(x){
            b = y;
            cout << "b = " << b << endl;
        }
};

int main(){
    B obj(2,3);
    return 0;
}