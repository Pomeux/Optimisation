#include<iostream>
#include<string>
#include<vector>
using namespace std;

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