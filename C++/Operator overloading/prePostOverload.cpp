#include<iostream>
using namespace std;

class Integer{
    private:
        int x;

    public:
        void setData(int i){
            x = i;
        }

        void showData(){
            cout << "x = " << x << endl;
        }

        Integer operator++(){
            Integer temp;
            temp.x = ++x;
            return temp;
        }

        Integer operator++(int){
            Integer temp;
            temp.x = x++;
            return temp;
        }
};

int main(){
    Integer p1, p2;
    p1.setData(3);
    // p2 = ++p1;
    p2 = p1++;
    p1.showData();
    p2.showData();
    return 0;
}