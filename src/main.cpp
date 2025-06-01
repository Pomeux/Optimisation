#include <iostream>
#include<vector>
#include"./KP/Local/Construction.cpp"

using namespace std;

int main() {

    Problem p;
    p.coef={18.0f,25.0f,11.0f,14.0f};
    p.poids={2.0f,2.0f,1.0f,1.0f};
    p.capacite=3;
    p.size=4;
    Sol sol=construction(p);


    return 0;
}

