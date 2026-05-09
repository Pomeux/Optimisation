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
	sort(U.begin(),U.end(),[](pair<float,int> a,pair<float,int> b){
      return a.first>b.first;
	});

    vector<int> solution(problem.size,0);

    for(int i=0;i<problem.size;i++) {

    	if(problem.poids_courant+problem.poids[U[i].second]<=problem.capacite) {
            problem.poids_courant+=problem.poids[U[i].second];

            solution[U[i].second]=1;

        }
    }

	sol.sol=solution;
   	return sol;
}


