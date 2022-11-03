#include<iostream>
using namespace std;

class Complex{
    private:
        int x;

    public:
        void setData(int i){
            x = i;
        }

        void showData(){
            cout << "x = " << x << endl;
        }

        friend void friendFunc(Complex);
};

void friendFunc(Complex c){
    cout << "sum = " << c.x + 5;
}

int main(){
    Complex c1;
    c1.setData(3);
    c1.showData();
    friendFunc(c1);
    return 0;
}