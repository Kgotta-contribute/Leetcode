#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int n = gas.size();

        int totalGas = 0;
        int currentGas = 0;
        int startStation = 0;

        for (int i = 0; i < n; ++i) {
            totalGas += gas[i] - cost[i];
            currentGas += gas[i] - cost[i];

            // If currentGas becomes negative, reset the startStation and currentGas
            if (currentGas < 0) {
                startStation = i + 1;
                currentGas = 0;
            }
        }

        // If totalGas is negative, it means there is no solution
        return (totalGas >= 0) ? startStation : -1;
    }
};
