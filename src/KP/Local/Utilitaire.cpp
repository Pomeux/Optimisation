#include<iostream>
#include<string>
#include<vector>
using namespace std;
template<class T>
bool compar_decroissant(T a,T b) {
     return a>b;
}

namespace Utilitaire {
    string tab_to_string(vector<vector<int>> tab) {
        string s="";
        for (int i=0;i<tab.size();i++) {
            for (int j=0;j<tab[i].size();j++) {
                s+=to_string(tab[i][j]);
            }
            s+="\n";
        }
        return s;
    }
}