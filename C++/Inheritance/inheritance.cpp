#include<iostream>
using namespace std;

class A{
    int x;
    
    public:
      void setData(int i){
        x = i;
        cout << x << "\n";
      }
};

class B:protected A{
    public:
       void accessFunc(){
            setData(2);
       }
};

class C:public A{
    public:
       void accessFunc(){
            // setData(2);
       }
};

int main(){
    B obj1;
    C obj2;
    obj1.accessFunc();
    obj2.setData(3);
    return 0;
}

//OUTPUT
//2
//3