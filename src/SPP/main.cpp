#include <iostream>
#include"../Utilitaire/Parser.cpp"
#include"../Utilitaire/Utilitaire.cpp"
#include "Local/Construction.cpp"

using namespace std;



int main() {

 

    try {
        SPP::Problem problem=SPP::parser("pb_100rnd0100");
      /*  for (int i=0;i<problem.one_position.size();i++) {
            cout << (i+1);
            for (int j=0;j<problem.one_position[i].size();j++) {
                cout <<" " << problem.one_position[i][j];
            }
            cout << endl;
        }*/

            SPP::Sol s=construction(problem);
        for (int i=0;i<s.sol.size();i++) {
            cout << s.sol[i] << endl;
        }



    } catch (exception e) {
        cout << e.what() << endl;
    }
    return 0;
}
