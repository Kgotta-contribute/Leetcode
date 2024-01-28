#include <vector>
#include <unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int result = 0;

        // Preprocess to calculate the prefix sum of each row
        for (int i = 0; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        // Iterate over all possible pairs of columns
        for (int col1 = 0; col1 < cols; ++col1) {
            for (int col2 = col1; col2 < cols; ++col2) {
                unordered_map<int, int> prefixSumCount;
                prefixSumCount[0] = 1;
                int currentSum = 0;

                // Iterate over all rows and calculate the sum in the current submatrix
                for (int row = 0; row < rows; ++row) {
                    int sum = matrix[row][col2] - (col1 > 0 ? matrix[row][col1 - 1] : 0);
                    currentSum += sum;

                    // Check if there is a prefix sum that makes the current sum equal to the target
                    if (prefixSumCount.find(currentSum - target) != prefixSumCount.end()) {
                        result += prefixSumCount[currentSum - target];
                    }

                    // Update the prefix sum count
                    prefixSumCount[currentSum]++;
                }
            }
        }

        return result;
    }
};
