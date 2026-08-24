//
// Created by leo on 22/08/2026.
//

#pragma once

#include <vector>
#include <bits/stdc++.h>

using namespace std;

namespace Knapsack
{
    struct KnapsackProblem {
        vector<int> weights;
        vector<int> coefficients;
        size_t capacity;
        size_t size;


    };

    struct KnapSackSolution {
        KnapSackSolution(const vector<int> &solution,size_t objective_value,size_t capacity_reached);
        vector<int> solution;
        size_t objective_value;
        size_t capacity_reached;

        vector<int> index_one;
        vector<int> index_zero;



    };

}