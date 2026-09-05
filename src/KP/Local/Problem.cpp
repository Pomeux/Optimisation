#include <vector>
#include <bits/stdc++.h>
#include <stdexcept>

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