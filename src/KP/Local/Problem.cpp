#include<vector>

using namespace std;

namespace Knapsack
{
    struct KnapsackProblem {
        vector<int> weights;
        vector<int> coefficients;
        int capacity;
        size_t size;


    };

    struct KnapSackSolution {
        vector<int> solution;
        int objective_value;
        int capacity_reached;
        KnapsackProblem problem;
    };

}