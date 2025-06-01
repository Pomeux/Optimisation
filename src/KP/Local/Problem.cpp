#include<iostream>
#include<vector>

using namespace std;


namespace SPP {


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

//namespace KP {
    struct Problem {
        vector<float> poids;
        vector<float> coef;
        int poids_courant;
        int capacite;
        int size;
    };

    struct Sol {
        vector<int> sol; //renomer
        double z;
    };
//}