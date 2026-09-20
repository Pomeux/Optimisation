#include <vector>
#include <bits/stdc++.h>
#include <stdexcept>
#include <algorithm>

#include"Problem.h"

#pragma once

using namespace std;
using namespace Knapsack;

KnapSackSolution::KnapSackSolution(const vector<int> &solution,size_t objective_value,size_t capacity_reached):solution(solution),objective_value(objective_value),capacity_reached(capacity_reached)
{
    index_zero.reserve(solution.size());
    index_one.reserve(solution.size());

    for (int i=0;i<solution.size();i++)
    {
        switch (solution[i])
        {
        case 0:
            index_zero.push_back(i);
            break;
        case 1:
            index_one.push_back(i);
            break;
        default:
            throw invalid_argument("La solution du knapsack probleme n'est pas valide");
            break;
        }
    }
}

ostream &operator<<(ostream &os,const KnapsackProblem &problem)
{
    os << " capacity: " << problem.capacity << endl;

    for (int i=0;i<problem.size;i++)
    {
        os << " c: " << problem.coefficients[i] << "w: " << problem.weights[i];
    }
    os << endl;
    return os;
}


ostream &operator<<(ostream &os, const KnapSackSolution &solution)
{

    auto tab= [&os] (int i) {os << i << " ";};
    for_each(solution.solution.begin(),solution.solution.end(),tab);

    os << endl << "obj: " << solution.objective_value
    << " capacity reached: "
    << solution.capacity_reached << endl;

    os << "one: ";
    for_each(solution.index_one.begin(),solution.index_one.end(),tab);
    os << endl << "zero: ";
    for_each(solution.index_zero.begin(),solution.index_zero.end(),tab);

    return os;
}