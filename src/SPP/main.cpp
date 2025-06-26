#include <iostream>
#include"../Utilitaire/Parser.cpp"

using namespace std;


int main() {

 

    try {
        SPP::parser("pb_100rnd0100");


    } catch (exception e) {
        cout << e.what() << endl;
    }
    return 0;
}
