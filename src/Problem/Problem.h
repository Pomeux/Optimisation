//
// Created by Leo on 01/06/2025.
//
#include<string>
#include<vector>

using namespace std;

#ifndef PROBLEM_H
#define PROBLEM_H



class Problem {
    public:
        string to_string();
        double get_z();
        double caculate_z();
        int get_nb_variable();
        int get_nb_constrainte();
		vector<vector<double> > get_contrainte();

    private:
      double z;
      int contrainte;
      int variable;
      vector<vector<double> > constraintes;

};



#endif //PROBLEM_H
