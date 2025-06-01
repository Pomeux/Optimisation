#include<iostream>
#include<string>
#include<vector>
using namespace std;
template<class T>
bool compar_decroissant(T a,T b) {
     return a>b;
}

namespace Utilitaire {
    template<class T>
    string double_tab_to_string(vector<vector<T>> tab) {
        string s="";
        for (int i=0;i<tab.size();i++) {
            for (int j=0;j<tab[i].size();j++) {
                s+=to_string(tab[i][j]);
            }
            s+="\n";
        }
        return s;
    }
    template<class T>
    string tab_to_string(vector<T> tab) {
        string s="";
        for (int i=0;i<tab.size();i++) {
            s=s+" "+to_string(tab[i]);
        }
        return s;

    }
    template<class T,class V>
    string tab_pair_to_string(vector<pair<T,V>> tab) {
        string s="";
        for (int i=0;i<tab.size();i++) {
            s=s+" ("+to_string(tab[i].first)+","+to_string(tab[i].second)+")";
        }
        return s;

    }
}