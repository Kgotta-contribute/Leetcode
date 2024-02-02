#include <vector>

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Variables to check if the first row and column should be set to zero
        bool firstRowZero = false;
        bool firstColZero = false;

        // Check if the first row should be set to zero
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Check if the first column should be set to zero
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Use the first row and column to mark other rows and columns to be set to zero
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set rows to zero based on the first column
        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set columns to zero based on the first row
        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set the first row and column to zero if needed
        if (firstRowZero) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }

        if (firstColZero) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};