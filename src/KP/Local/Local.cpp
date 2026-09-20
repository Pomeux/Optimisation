#include <iostream>
#include "Problem.cpp"
#include "Operation.cpp"
#include <vector>




using namespace std;
using namespace Knapsack;
using namespace Operation;




enum TYPE_EXCHANGE
{
    ONE,
    ZERO
};


Neighbour exchange_1D(const KnapSackSolution &solution,const KnapsackProblem &problem,const vector<int> &vector_index, const TYPE_EXCHANGE type, const int size_neighbour)
{
    Neighbour neighbour(size_neighbour);

    int signe = type==ONE ? 1: -1;

    MoveType move_type = type==ONE? EXCHANGE_1_0: EXCHANGE_0_1;

    for (int i=0;i<vector_index.size();i++)
    {
        int new_objectif_value = solution.objective_value+
    signe*problem.coefficients[vector_index[i]];

        int new_weight_value = solution.capacity_reached+
            signe*problem.weights[vector_index[i]];

        Move move {.objective_value = new_objectif_value,.weight_value = new_weight_value,.feasible = new_weight_value<=problem.capacity, .move_type = move_type};

        if (type == ONE)
            move.index_put1 = vector_index[i];
        else
            move.index_pop1 = vector_index[i];

        neighbour.add_move(move);
    }
    return neighbour;
}
//modif sens solution et problem
Neighbour one_zero_exchange(const KnapSackSolution &solution,const KnapsackProblem &problem)
{
    return exchange_1D(solution,problem,solution.index_zero,ONE,solution.index_zero.size());
}
Neighbour zero_one_exchange(const KnapSackSolution &solution,const KnapsackProblem &problem)
{
    return exchange_1D(solution,problem,solution.index_one,ZERO,solution.index_one.size());
}
Neighbour one_one_exchange(const KnapSackSolution &solution, const KnapsackProblem &problem)
{
    Neighbour neighbour(solution.index_one.size()*solution.index_zero.size());
    for (int i=0;i<solution.index_one.size();i++)
    {
        for (int j=0;j<solution.index_zero.size();j++)
        {
            int index_pop = solution.index_one[i];
            int index_put = solution.index_zero[j];

            int objective_value_new = solution.objective_value+problem.coefficients[index_put]-problem.coefficients[index_pop];
            int weight_value_new = solution.capacity_reached+problem.weights[index_put]-problem.weights[index_pop];


            Move move{.index_put1 = index_put,.index_pop1 = index_pop,.objective_value = objective_value_new,.weight_value = weight_value_new,.feasible = weight_value_new<=problem.capacity,.move_type = EXCHANGE_1_1};
            neighbour.add_move(move);
        }
    }
    return neighbour;
}

Neighbour exchange_2D(const KnapSackSolution &solution,const KnapsackProblem &problem,const vector<int> &principal,const vector<int> &secondary,TYPE_EXCHANGE type)
{
    Neighbour neighbour(principal.size()*principal.size()*solution.index_one.size());
    int signe = type==ONE ? 1 : -1;
    MoveType move_type = type==ONE? EXCHANGE_2_1: EXCHANGE_1_2;

    for (int i=0;i<secondary.size();i++)
    {
        for (int j=0;j<principal.size();j++)
        {
            for (int k=j+1;k<principal.size();k++)
            {
                int index_secondary_1 = secondary[i];

                int index_principal_1 = principal[j];
                int index_principal_2 = principal[k];


                int objective_value_new = solution.objective_value+
                            signe*problem.coefficients[index_principal_1]+
                            signe*problem.coefficients[index_principal_2]-
                                signe*problem.coefficients[index_secondary_1];


                int weight_value_new = solution.capacity_reached+
                            signe*problem.weights[index_principal_1]+
                            signe*problem.weights[index_principal_2]-
                            signe*problem.weights[index_secondary_1];

                Move move {.objective_value = objective_value_new,
                    .weight_value = weight_value_new,
                    .feasible = weight_value_new<=problem.capacity,
                    .move_type =  move_type
                };
                if (type == ONE)
                {

                    move.index_put1 = index_principal_1;
                    move.index_put2 = index_principal_2;
                    move.index_pop1 = index_secondary_1;
                }
                else
                {
                    move.index_pop1 = index_principal_1;
                    move.index_pop2 = index_principal_2;
                    move.index_put1 = index_secondary_1;
                }

                neighbour.add_move(move);

            }
        }

    }
    return neighbour;
}
Neighbour exchange_two_one(const KnapSackSolution &solution,const KnapsackProblem &problem)
{
    return exchange_2D(solution,problem,solution.index_zero,solution.index_one,ONE);
}
Neighbour exchange_one_two(const KnapSackSolution &solution,const KnapsackProblem &problem)
{
    return exchange_2D(solution,problem,solution.index_one,solution.index_zero,ZERO);
}

Neighbour exchange_two_two(const KnapSackSolution &solution,const KnapsackProblem &problem)
{
    Neighbour neighbour(solution.index_one.size()*solution.index_one.size()*solution.index_zero.size()*solution.index_zero.size());

    for (int i=0;i<solution.index_zero.size();i++)
    {
        for (int j=i+1;j<solution.index_zero.size();j++)
        {
            for (int x=0;x<solution.index_one.size();x++)
            {
                for (int y=x+1;y<solution.index_one.size();y++)
                {
                    int index_put_1 = solution.index_zero[i];
                    int index_put_2 = solution.index_zero[j];

                    int index_pop_1 = solution.index_one[x];
                    int index_pop_2 = solution.index_one[y];

                    int objective_value_new = solution.objective_value +
                        problem.coefficients[index_put_1] +
                            problem.coefficients[index_put_2] +
                                problem.coefficients[index_pop_1] -
                                    problem.coefficients[index_pop_2];


                    int weight_value_new = solution.capacity_reached +
                        problem.weights[index_put_1] +
                            problem.weights[index_put_2] +
                                problem.weights[index_pop_1] -
                                    problem.weights[index_pop_2];

                    Move move{.index_put1 = index_put_1,
                        .index_put2 = index_put_2,
                        .index_pop1 = index_pop_1,
                        .index_pop2 = index_pop_2,
                        .objective_value  = objective_value_new,
                        .weight_value = weight_value_new,
                        .feasible = weight_value_new <=problem.capacity,
                        .move_type = EXCHANGE_2_2
                        };

                        neighbour.add_move(move);
                }
            }
        }
    }
    return neighbour;
}