#include<iostream>
using namespace std;

class Complex{
    private:
        int x, y;

    public:
        void setData(int i, int j){
            x = i;
            y = j;
        }

        void showData(){
            cout << "x = " << x << endl;
        }

        friend Complex operatorOverload(Complex, Complex);

};

Complex operatorOverload(Complex a, Complex b){
    cout << "sum of x = " << a.x + b.x << "\n";
    cout << "sum of y = " << a.y + b.y;
}

int main(){
    Complex c1, c2;
    c1.setData(3, 4);
    c2.setData(6, 7);
    operatorOverload(c1, c2);
    return 0;
}