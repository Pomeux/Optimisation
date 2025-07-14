
#include <bits/stdc++.h>
#include<vector>
#include<iostream>

using namespace std;

namespace SPP {

    Sol construction(Problem problem) {
	    Sol solution;
    	vector<int> sol(problem.activite,0);

    	vector<pair<float, int>> u(problem.activite);
    	vector<int> compt(problem.activite,0);
    	vector<bool> occupe(problem.ressource,false);
    	cout << problem.tab.size() << endl;

    	for(int i=0;i<problem.activite;i++) {
    		for(int j=0;j<problem.ressource;j++) {
    			if(problem.tab[j][i]==1) {
    				compt[i]+=1;
    			}

    		}
    		u[i]={problem.coef[i]/compt[i],i};
    	}
    	sort(u.begin(),u.end());

    	while(!u.empty()) {
    		pair<float,int> val=u[u.size()-1];
    		u.pop_back();
    		cout<< val.first<<" "<<val.second<<endl;
    		bool pass=true;
    		int i=0;
    		while(i>=problem.one_position[i].size()) {
    			if(occupe[problem.one_position[val.second][i]]==true) {
    				pass=false;
    				break;
    			}
    			i++;
    		}

    		if(pass) {
    			//pbp ici
    			solution.sol[val.second]=1;
    			for(int i=0;i<problem.one_position[val.second].size();i++) {
    				occupe[problem.one_position[val.second][i]]=true;
    			}
    		}
    	}
    	return solution;
    }

//voir équivalent classes anonyme pour cpp


}