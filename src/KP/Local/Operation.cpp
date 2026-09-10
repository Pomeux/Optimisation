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
    if (move.objective_value>total[index_best_move].objective_value)
    {
        index_best_move = total.size()-1;

        if (move.feasible)
            index_best_move_feasible = index_best_move;
    }


}


ostream& operator<<(ostream &os,const Move &move)
{
    switch (move.move_type)
    {
    case EXCHANGE_1_0:
        os << "EX10" << " put: " << move.index_put1;
        break;
    case EXCHANGE_0_1:
        os << "EX01" << " pop: " << move.index_pop1;
        break;
    case EXCHANGE_1_1:
        os << "EX11" << " put: " << move.index_put1 << " pop: " << move.index_pop1;
    }
    os << "obj: " << move.objective_value << " weight: " << move.weight_value << " feasible: " << move.feasible;
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
