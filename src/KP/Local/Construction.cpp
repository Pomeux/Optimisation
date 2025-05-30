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

    vector<int> solution(problem.size,0);

	//pb il faut conserver l'indice
	while (i<problem.size && ) {

	}
    for(int i=0;i<problem.size;i++) {
        if(problem.poids_courant+U[i]<problem.capacite) {
            problem.poids_courant+=U[i];
            solution[i]=1;
        }
    }

	sol.sol=solution;
   	return sol;
}


