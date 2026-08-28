//
// Created by leo on 28/08/2026.
//

# pragma once

#include <vector>

using namespace std;

namespace Operation
{
    enum MoveType
    {
        EXCHANGE_0_1,
        EXCHANGE_1_0,
        EXCHANGE_1_1,
        EXCHANGE_2_1,
        EXCHANGE_1_2,
        EXCHANGE_2_2
    };

    struct Move
    {
        int index_put1;
        int index_put2;
        int index_pop1;
        int index_pop2;

        int objective_value;
        int weight_value;

        bool feasible;

        MoveType move_type;

    };
    struct Neighbour
    {
        Neighbour(int n);
        void add_neighbour(const Move &move);

        size_t index_best_move = 0;
        vector<Move> total;

    };
}