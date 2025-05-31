#include <iostream>
#include<vector>
#include"./KP/Local/Construction.cpp"

using namespace std;

int main() {

    Problem p;
    p.coef={18,25,11,14};
    p.poids={2,2,1,1};
    p.capacite=3;
    p.size=4;
   // Sol sol=construction(p);

    /*for (int i=0;i<sol.sol.size();i++) {
        cout << sol.sol[i] << " ";
    }*/
    pair<int,int> s={1,1};
    cout << to_string(s);
    return 0;
}

