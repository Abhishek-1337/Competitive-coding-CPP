#include<iostream>
using namespace std;

class Unary{
    private:
        int x;

    public:
        void setData(int i){
            x = i;
        }

        void showData(){
            cout << "x = " << x << endl;
        }

        Unary operator-(){
            Unary temp;
            temp.x = -x;
            return temp;
        }
};

class Binary{

    private: 
        int a, b;

    public:
       void setData(int i, int j){
            a = i;
            b = j;
       }
       
       void showData(){
         cout << "a = " << a << " " << "b = " << b << endl;
       }

       Binary add(Binary c){
            Binary temp;
            temp.a = a + c.a;
            temp.b = b + c.b;
            return temp;
       }

       Binary operator+(Binary c){
            Binary temp;
            temp.a = a + c.a;
            temp.b = b + c.b;
            return temp;
       }
};

int main(){
    Binary c1, c2,c3;
    c1.setData(3, 4);
    c2.setData(4, 6);
    c1.showData();
    c3 = c2.add(c1);
    c3 = c2 + c1;  // Or you can call it like c3 = c2.operator+(c1);
    c3.showData();
    
    Unary u1, u2;
    u1.setData(4);
    u2 =- u1; // Another way of calling it is u2 = u1.operator-(); u1 is the caller
    u1.showData();
    u2.showData();
    return 0;
}