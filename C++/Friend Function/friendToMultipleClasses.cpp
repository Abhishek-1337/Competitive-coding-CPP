#include<iostream>
using namespace std;

class B; //Formal declaration of class before calling friend function from any of the classes.
class A{
    private:
        int x;

    public:
        void setData(int i){
            x = i;
        }

        void showData(){
            cout << "x = " << x << endl;
        }

        friend void commonFriend(A, B); //declared the friend function using just the type of arguments.
};

class B{
    int x;
    public:
      void setData(int i){
        x = i;
      }

      friend void commonFriend(A, B);
};

void commonFriend(A a, B b){
    cout << "sum = " << a.x + b.x ;
}

int main(){
    A a;
    B b;
    a.setData(3);   
    b.setData(4);   
    commonFriend(a, b);
    return 0;
}