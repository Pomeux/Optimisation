#include <iostream>
#include"../Utilitaire/Parser.cpp"
#include "Local/Construction.cpp"

using namespace std;



int main() {

 

    try {
        SPP::Problem problem=SPP::parser("didacticSPP");

      /*  for (int i=0;i<problem.one_position.size();i++) {
            cout << (i+1);
            for (int j=0;j<problem.one_position[i].size();j++) {
                cout <<" " << problem.one_position[i][j];
            }
            cout << endl;
        }*/
        construction(problem);

        Regler bug et voir comment gérere les includes avec plusieurs fichiers

    } catch (exception e) {
        cout << e.what() << endl;
    }
    return 0;
}
