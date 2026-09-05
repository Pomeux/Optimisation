#include <iostream>
#include "Problem.cpp"
#include <vector>


using namespace std;
using namespace Knapsack;

template<typename T>
auto print_tab = [](const vector<T> &tab) {
    for (T t:tab)
    {
        cout << t << " ";
    }
};

KnapSackSolution greedy_knapsack(const KnapsackProblem &problem) {
    vector<pair<float,int>> coeff_glutton(problem.size);
    vector<int> solution(problem.size);

    size_t current_weight = 0;
    size_t objective_value = 0;


    for (int i=0;i<problem.size;i++) {

        coeff_glutton[i]={static_cast<float>(problem.coefficients[i])/static_cast<float>(problem.weights[i]),i};
    }

    sort(coeff_glutton.begin(),coeff_glutton.end(), [] (const pair<float,int> &a,const pair<float,int> &b){

        return a.first>b.first;
    });

    for (int i=0;i<problem.size;i++) {

        int index_item = coeff_glutton[i].second;
        if (current_weight+problem.weights[index_item]<=problem.capacity) {

            current_weight += problem.weights[index_item];
            objective_value += problem.coefficients[index_item];
            solution[index_item] = 1;
        }
    }

    KnapSackSolution solution_knapsack(solution,objective_value,current_weight);

    return solution_knapsack;


}



/*
 *  6 4 1
 *  6 2 1
 */

/*
 *
 */
