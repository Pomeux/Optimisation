#include<iostream>
#include<fstream>
#include<string>
#include<stdexcept>
#include<vector>
#include"../SPP/Problem/Problem.cpp"
#include<filesystem>
#include<stdlib.h>
#include "Utilitaire.cpp"

using namespace std;

namespace SPP {
    Problem parser(string s) {
		Problem problem;

        s="../instance/SSP/"+s+".dat";

        ifstream fichier;
        fichier.open(s,ios::in);
    	cout << filesystem::current_path() << endl;
        cout << "a" << endl;
    	cout << s << endl;
        if(fichier.is_open()) {

        	string current;

        	fichier >> current;
        	int ressource=atoi(current.c_str());
        	fichier >> current;
        	int activite=atoi(current.c_str());

			vector<vector<int>> tab(ressource,vector<int>(activite));
			vector<int> coef(activite);

			problem.one_position=vector<vector<int>>(activite);
        	for (int i=0;i<activite;i++) {
        		fichier >> current;
        		coef[i]=atoi(current.c_str());
                problem.one_position[i].reserve(ressource);

        	}



        	for (int i=0;i<ressource;i++) {
        		fichier >> current;
				int nb_one=atoi(current.c_str());
        		for (int j=0;j<nb_one;j++) {
        			fichier >> current;
        			int one_position=atoi(current.c_str())-1;
        			tab[i][one_position]=1;

                    //cout << problem.one_position[one_position-1].capacity() << endl;
					problem.one_position[one_position].push_back((i+1));
        		}
        	}

            fichier.close();
			problem.tab=tab;
        	problem.coef=coef;
        	problem.ressource=ressource;
        	problem.activite=activite;
		} else {
			throw runtime_error("fichier pas ouvert");
		}



	return problem;

    }
}