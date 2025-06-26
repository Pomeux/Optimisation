//
// Created by Leo on 01/06/2025.
//
#include<string>
#include<vector>

using namespace std;

#ifndef PROBLEM_H
#define PROBLEM_H

enum ProblemType {
	MIN,
  	MAX
  };

class Problem {
    public:
		Problem();
		~Problem();
        string to_string();
		string get_nom() const;
        double get_z();
        double caculate_z();
        int get_nb_variable();
        int get_nb_constrainte();
		vector<vector<double> > get_contrainte();
        ProblemType get_type();
        vector<int> get_solution();



    private:
		double z;
		int contrainte;
		int variable;
		vector<vector<double> > constraintes;
        vector<double> coef; //coef de la fonction objectif
		vector<int> solution;
        ProblemType type;
        string nom;

};





#endif //PROBLEM_H
