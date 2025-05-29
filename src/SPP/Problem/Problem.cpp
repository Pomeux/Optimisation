#include<iostream>
#include<vector>

namespace SPP {
    using namespace std;

    struct Problem {
        vector<vector<int>> tab;
        vector<int> coef;
        int ressource; //ligne
        int activite; //colonne
    };

    struct Sol {
        vector<int> sol;
        vector<int> One;
        vector<int> Zero;
    };
}