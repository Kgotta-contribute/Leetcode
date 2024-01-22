// VERY VERY HARD

#include <vector>
using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int rows = grid.size();
        int cols = grid[0].size();
        int closedIslands = 0;

        // Mark the boundary land as visited
        for (int i = 0; i < rows; ++i) {
            dfs(grid, i, 0);
            dfs(grid, i, cols - 1);
        }

        for (int j = 0; j < cols; ++j) {
            dfs(grid, 0, j);
            dfs(grid, rows - 1, j);
        }

        // Count the closed islands in the remaining unvisited land
        for (int i = 1; i < rows - 1; ++i) {
            for (int j = 1; j < cols - 1; ++j) {
                if (grid[i][j] == 0) {
                    ++closedIslands;
                    dfs(grid, i, j);
                }
            }
        }

        return closedIslands;
    }

private:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 0) {
            return;
        }

        grid[i][j] = 1;  // Mark as visited
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};

// int main() {
//     Solution solution;
//     vector<vector<int>> grid = {
//         {1, 1, 1, 1, 1, 1, 1, 0},
//         {1, 0, 0, 0, 0, 1, 1, 0},
//         {1, 0, 1, 0, 1, 1, 1, 0},
//         {1, 0, 0, 0, 0, 1, 0, 1},
//         {1, 1, 1, 1, 1, 1, 1, 0}
//     };
//     int result = solution.closedIsland(grid);
//     cout << "Number of Closed Islands: " << result << endl;
//     return 0;
// }
