#include <iostream>
#include "Problem.cpp"
#include "Operation.cpp"
#include <vector>
#include <stdexcept>

using namespace std;
using namespace Knapsack;
using namespace Operation;


enum TYPE_EXCHANGE
{
    ONE,
    ZERO
};

KnapSackSolution research_local(const KnapSackSolution &solution)
{

}
Neighbour exchange_1D(const KnapSackSolution &solution,const KnapsackProblem &problem,const vector<int> &vector_index, const TYPE_EXCHANGE type, const int size_neighbour)
{
    Neighbour neighbour(size_neighbour);

    int signe = type==ONE ? 1: -1;

    for (int i=0;i<vector_index.size();i++)
    {
        int new_objectif_value = solution.objective_value+
    signe*problem.coefficients[vector_index[i]];

        int new_weight_value = solution.capacity_reached+
            signe*problem.weights[vector_index[i]];

        Move move {.objective_value = new_objectif_value,.weight_value = new_weight_value,.feasible = new_weight_value<=problem.capacity};

        if (type == ONE)
            move.index_put1 = i;
        else
            move.index_pop1 = i;

        neighbour.add_move(move);
    }
    return neighbour;
}

Neighbour one_zero_exchange(const KnapSackSolution &solution,const KnapsackProblem &problem)
{
    return exchange_1D(solution,problem,solution.index_one,ONE,solution.index_zero.size());
}
Neighbour zero_one_exchange(const KnapSackSolution &solution,const KnapsackProblem &problem)
{
    return exchange_1D(solution,problem,solution.index_zero,ONE,solution.index_one.size());
}
Neighbour zero_one_exchange(const KnapSackSolution &solution,const KnapsackProblem &problem)
{
    Neighbour neighbour(solution.index_one.size());
    for (int i=0;i<solution.index_zero.size();i++)
    {
        int new_objectif_value = solution.objective_value-
            problem.coefficients[solution.index_zero[i]];
        int new_weight_value = solution.capacity_reached-
            problem.weights[solution.index_zero[i]];

        Move move{.index_pop1 = i,.objective_value = new_objectif_value,.weight_value = new_weight_value,.feasible = new_weight_value<=problem.capacity};
        neighbour.add_move(move);
    }
    return neighbour;
}


