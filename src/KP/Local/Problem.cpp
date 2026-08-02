#include<vector>

using namespace std;

namespace Knapsack
{
    struct KnapsackProblem {
        vector<float> weights;
        vector<float> coefficients;
        int capacity;
        int size;
    };

    struct KnapSackSolution {
        vector<int> solution;
        int objective_value;
        int capacity_reached;
        KnapsackProblem problem;
    };
}