#include"../Problem/Problem.cpp"
#include"Utilitaire.cpp"
#include <bits/stdc++.h>
#include<vector>
#include<iostream>

using namespace std;

namespace SPP {

    Sol construction(Problem problem) {
          vector<pair<float, int>> u(problem.activite);
          vector<int> compt(problem.activite,0);


          for(int i=0;i<problem.activite;i++) {
            for(int j=0;j<problem.ressource;j++) {
                if(problem.tab[i][j]==1) {
                    compt[i]+=1;
                }

            }
            u[i]={problem.coef[i]/compt[i],i};
          }
           sort(u.begin(),u.end());
           while(!u.empty()) {
               pair<float,int> val=u[u.size()-1];
               u.pop_back();

           }


//voir équivalent classes anonyme pour cpp
     }

}