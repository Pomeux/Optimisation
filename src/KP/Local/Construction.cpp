#include<iostream>
#include"Problem.cpp"
#include<vector>
#include"Utilitaire.cpp"
#include <bits/stdc++.h>

using namespace std;

Sol construction(Problem problem) {
 	Sol sol;

	vector<float> U(problem.size,0);
    for(int i=0;i<problem.size;i++) {
		U[i]=problem.coef[i]/problem.poids[i];

    }
	sort(U.begin(),U.end(),compar_decroissant<float>);
    for(int i=0;i<problem.size;i++) {
        if(problem.poids_courant+U[i]<problem.capacite) {

        }
    }


   	return sol;
}


