//
// Created by leo on 28/08/2026.
//
#include "Operation.h"
using namespace Operation;

Neighbour::Neighbour(int n)
{
    total.reserve(n);
}
void Neighbour::add_neighbour(const Move &move)
{
    total.push_back(move);
    if (move.feasible && move.objective_value>total[index_best_move].objective_value)
        index_best_move=total.size()-1;
}