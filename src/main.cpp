#include <iostream>
#include<vector>
#include"./KP/Local/Construction.cpp"

using namespace std;



class Test {
public:
    int a;
    Test(int a) {
        this->a=a;
    }

};
class B: public Test {
public:
    int b;
    B(int a,int b):Test(a) {
        this->a=2;
    }

};

int main() {
    B b(1,2);
    b.a=3;


    return 0;
}
