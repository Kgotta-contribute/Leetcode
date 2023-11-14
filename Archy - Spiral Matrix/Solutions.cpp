#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        if (matrix.empty() || matrix[0].empty()) {
            return result;
        }

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // Traverse from left to right
            for (int i = left; i <= right; ++i) {
                result.push_back(matrix[top][i]);
            }
            top++;

            // Traverse from top to bottom
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            right--;

            // Traverse from right to left
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Traverse from bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result1 = solution.spiralOrder(matrix1);
    cout << "Example 1 Output: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<vector<int>> matrix2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> result2 = solution.spiralOrder(matrix2);
    cout << "Example 2 Output: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
