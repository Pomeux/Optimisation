#include<iostream>
#include"Problem.cpp"
#include<vector>
#include <bits/stdc++.h>


using namespace std;
using namespace Knapsack;

KnapSackSolution glouton_knapsack(const KnapsackProblem &problem) {
    vector<pair<float,int>> coeff_glutton(problem.size);
    vector<int> solution(problem.size);

    int current_weight = 0;
    int objective_value = 0;

    for (int i=0;i<problem.size;i++) {

        coeff_glutton[i]={problem.coefficients[i]/problem.weights[i],i};
    }
    sort(coeff_glutton.begin(),coeff_glutton.end(), [] (const pair<float,int> &a,const pair<float,int> &b){

        return a.first>=b.first;
    });
    for (int i=0;i<problem.size;i++) {

        int index_item = coeff_glutton[i].second;
        if (current_weight+problem.weights[index_item]<problem.capacity) {

            current_weight += problem.weights[index_item];
            objective_value += problem.coefficients[index_item];
            solution[index_item] = 1;
        }
    }
    KnapSackSolution solution_knapsack{solution,objective_value,current_weight,problem};

    return solution_knapsack;

}

int main() {
    cout << "test";

    return 0;
}