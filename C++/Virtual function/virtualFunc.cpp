#include<iostream>
using namespace std;

class A{
    public:
        virtual void f1(){
            cout << "Parent f1" << endl;
        }
        virtual void f2(){
            cout << "Parent f2" << endl;
        }
        void f3(){
            cout << "Parent f3" << endl;
        }
        virtual void f4(){
            cout << "Parent f4" << endl;
        }
};

class B:public A{
    public:
     void f1(){
            cout << "Child f1" << endl;
     }
     void f2(){
         cout << "Child f2" << endl;
     }
     void f4(int a){
         cout << "Child f4 = " << a << endl;
     }
};

int main(){
    A obj, *p;
    B obj2;
    p = &obj2;
    p->f1();
    p->f4();
    // obj2.f4();
    p->f4(2);  //Early binding will give an error cause there is no more f4 without argument 
    return 0;
}