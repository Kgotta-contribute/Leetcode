#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        
        if (numRows <= 0) {
            return result;
        }
        
        result.push_back({1});
        
        for (int i = 1; i < numRows; ++i) {
            vector<int> row;
            row.push_back(1);
            
            for (int j = 1; j < i; ++j) {
                row.push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
            
            row.push_back(1);
            
            result.push_back(row);
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    int numRows = 5; 
    vector<vector<int>> result = solution.generate(numRows);
    
    for (const vector<int>& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}



// Initialize an empty vector of vectors result to store the triangle:
// result = []
// Check if numRows is less than or equal to 0. In this case, it's not, so we continue.

// Push the first row, which is [1], into the result:
// result = [[1]]
// Now, we iterate from i = 1 to i < numRows, which means we go from the 2nd row to the 5th row:

// For i = 1 (2nd row):

// Initialize an empty vector row to store this row: row = []
// Push 1 at the beginning of the row: row = [1]
// Now, we enter a nested loop to fill the middle elements of the row:
// For j = 1:
// Calculate row[j] = result[i - 1][j - 1] + result[i - 1][j], which is row[1] = result[0][0] + result[0][1] = 1 + 0 = 1
// Push this value into the row: row = [1, 1]
// Push 1 at the end of the row: row = [1, 1]
// Push this row into the result: result = [[1], [1, 1]]
// For i = 2 (3rd row):

// Initialize an empty vector row to store this row: row = []
// Push 1 at the beginning of the row: row = [1]
// Now, we enter a nested loop to fill the middle elements of the row:
// For j = 1:
// Calculate row[j] = result[i - 1][j - 1] + result[i - 1][j], which is row[1] = result[1][0] + result[1][1] = 1 + 1 = 2
// Push this value into the row: row = [1, 2]
// Push 1 at the end of the row: row = [1, 2, 1]
// Push this row into the result: result = [[1], [1, 1], [1, 2, 1]]
// Repeat the same process for i = 3 (4th row) and i = 4 (5th row).

// After completing the loop, the result contains the Pascal's Triangle with 5 rows:
// result = [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]