#include<iostream>
#include"Problem.cpp"
#include<vector>
#include"Utilitaire.cpp"
#include <bits/stdc++.h>

using namespace std;

Sol construction(Problem problem) {
 	Sol sol;

	vector<pair<float,int>> U(problem.size);
    for(int i=0;i<problem.size;i++) {
		U[i]={problem.coef[i]/problem.poids[i],i};

    }
	sort(U.begin(),U.end(),compar_decroissant<pair<float,int>>);

    vector<int> solution(problem.size,0);


    for(int i=0;i<problem.size;i++) {

    	if(problem.poids_courant+problem.poids[U[i].second]<problem.capacite) {
            problem.poids_courant+=problem.poids[U[i].second];
    		cout << problem.coef[U[i].second] << endl;
            solution[U[i].second]=1;

        }
    }

	sol.sol=solution;
   	return sol;
}


