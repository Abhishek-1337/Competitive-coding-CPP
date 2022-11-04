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

        friend ostream& operator<<(ostream&, Complex);
        friend istream& operator>>(istream&, Complex&);
};

ostream& operator<<(ostream& dout ,Complex c){
    cout << "a = " << c.x << " " << "b = " << c.y;
    return dout;
}

istream& operator>>(istream& din ,Complex &c){
    cin >> c.x >> c.y;
    return din;
}

int main(){
    Complex c1;
    cin >> c1;
    cout << c1;   
    return 0;
}