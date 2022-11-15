//Method overloading is done in the member of the same class not the different classes
//Method overriding is helpful in overriding stuff that we wouldn't want user to call

#include<iostream>

using namespace std;

class A{
    public:
        void f1(){
            cout << "Parent class f1" << "\n";
        }

        void f2(){
            cout << "Parent class f2" << "\n";
        }
};

class B:public A{
    public:
        void f1(){
            cout << "Child class f1" << "\n";
        }

        void f2(int a){                         //Method hiding 
            cout << "Child class f2 and a = "<< a << "\n"; 
        }
};

int main(){
    B obj;
    //obj.f2();                   //Even though f2 function without parameter exists in parent it still wouldn't call it
    obj.f1();
    obj.f2(2);
    return 0;
}