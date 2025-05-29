#include <iostream>
#include"Utilitaire/Parser.cpp"

using namespace std;


int main() {

 

    try {
        Utilitaire::parser("pb_100rnd0100");


    } catch (exception e) {
        cout << e.what() << endl;
    }
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.