//
// Created by leo on 28/08/2026.
//
#include "Operation.h"
#include <iostream>
using namespace Operation;

Neighbour::Neighbour(size_t n)
{
    total.reserve(n);
}
void Neighbour::add_move(const Move &move)
{
    total.push_back(move);
    if (move.feasible && move.objective_value>total[index_best_move].objective_value)
        index_best_move=total.size()-1;
}


std::ostream& operator<<(std::ostream &os,const Move &move)
{
    switch (move.move_type)
    {
    case EXCHANGE_1_0:
        os << "EX10" << " put1:" << move.index_put1;
        break;
    case EXCHANGE_0_1:
        os << "EX01" << " pop1:" << move.index_pop1;
        break;
    }
    os << "obj " << move.objective_value << " weight" << move.weight_value;
    return os;
}

std::ostream& operator<<(std::ostream &os,const Neighbour &neighbour)
{
    for (const Move &move:neighbour.total)
    {
        os << move << endl;
    }
    return os;
}
