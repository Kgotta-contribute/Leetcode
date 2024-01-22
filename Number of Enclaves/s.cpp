#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int result = 0;

        // Define directions for 4 adjacent cells
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        // BFS to mark land cells connected to the boundary
        queue<pair<int, int>> bfsQueue;

        // Start from the boundary and mark connected land cells
        for (int i = 0; i < row; ++i) {
            for (int j : {0, col - 1}) {
                if (grid[i][j] == 1) {
                    bfsQueue.push({i, j});
                    grid[i][j] = 0;  // Mark as visited
                }
            }
        }

        for (int j = 0; j < col; ++j) {
            for (int i : {0, row - 1}) {
                if (grid[i][j] == 1) {
                    bfsQueue.push({i, j});
                    grid[i][j] = 0;  // Mark as visited
                }
            }
        }

        // BFS to mark land cells connected to the boundary
        while (!bfsQueue.empty()) {
            int x = bfsQueue.front().first;
            int y = bfsQueue.front().second;
            bfsQueue.pop();

            // Explore four directions
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 1) {
                    bfsQueue.push({nx, ny});
                    grid[nx][ny] = 0;  // Mark as visited
                }
            }
        }

        // Count remaining unvisited land cells
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                result += grid[i][j];
            }
        }

        return result;
    }
};





// #include <vector>
// #include <queue>
// class Solution {
// public:
//     int numEnclaves(std::vector<std::vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int result = 0;

//         // Define directions for 4 adjacent cells
//         int dx[] = {-1, 0, 1, 0};
//         int dy[] = {0, 1, 0, -1};

//         // BFS to mark land cells connected to the boundary
//         std::queue<std::pair<int, int>> bfsQueue;

//         // Start from the boundary and mark connected land cells
//         for (int i = 0; i < m; ++i) {
//             for (int j : {0, n - 1}) {
//                 if (grid[i][j] == 1) {
//                     bfsQueue.push({i, j});
//                     grid[i][j] = 0;  // Mark as visited
//                 }
//             }
//         }

//         for (int j = 0; j < n; ++j) {
//             for (int i : {0, m - 1}) {
//                 if (grid[i][j] == 1) {
//                     bfsQueue.push({i, j});
//                     grid[i][j] = 0;  // Mark as visited
//                 }
//             }
//         }

//         // BFS to mark land cells connected to the boundary
//         while (!bfsQueue.empty()) {
//             int x = bfsQueue.front().first;
//             int y = bfsQueue.front().second;
//             bfsQueue.pop();

//             // Explore four directions
//             for (int k = 0; k < 4; ++k) {
//                 int nx = x + dx[k];
//                 int ny = y + dy[k];

//                 if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
//                     bfsQueue.push({nx, ny});
//                     grid[nx][ny] = 0;  // Mark as visited
//                 }
//             }
//         }

//         // Count remaining unvisited land cells
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 result += grid[i][j];
//             }
//         }

//         return result;
//     }
// };








// #include <vector>
// #include <queue>
// using namespace std;

// class Solution {
// public:
//     int numEnclaves(vector<vector<int>>& grid) {
//         int row = grid.size();
//         int col = grid[0].size();
//         int result = 0;

//         // Define directions for 4 adjacent cells
//         int dx[] = {-1, 0, 1, 0};
//         int dy[] = {0, 1, 0, -1};

//         // BFS to mark land cells connected to the boundary
//         markConnectedCells(grid, row, col, dx, dy);

//         // Count remaining unvisited land cells
//         for (int i = 0; i < row; ++i) {
//             for (int j = 0; j < col; ++j) {
//                 result += grid[i][j];
//             }
//         }

//         return result;
//     }

// private:
//     void bfs(vector<vector<int>>& grid, int x, int y, int row, int col, const int* dx, const int* dy) {
//         queue<pair<int, int>> bfsQueue;
//         bfsQueue.push({x, y});
//         grid[x][y] = 0; // Mark as visited

//         while (!bfsQueue.empty()) {
//             int currX = bfsQueue.front().first;
//             int currY = bfsQueue.front().second;
//             bfsQueue.pop();

//             // Explore four directions
//             for (int k = 0; k < 4; ++k) {
//                 int nx = currX + dx[k];
//                 int ny = currY + dy[k];

//                 if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 1) {
//                     bfsQueue.push({nx, ny});
//                     grid[nx][ny] = 0; // Mark as visited
//                 }
//             }
//         }
//     }

//     void markConnectedCells(vector<vector<int>>& grid, int row, int col, const int* dx, const int* dy) {
//         for (int i = 0; i < row; ++i) {
//             for (int j : {0, col - 1}) {
//                 if (grid[i][j] == 1) {
//                     bfs(grid, i, j, row, col, dx, dy);
//                 }
//             }
//         }

//         for (int j = 0; j < col; ++j) {
//             for (int i : {0, row - 1}) {
//                 if (grid[i][j] == 1) {
//                     bfs(grid, i, j, row, col, dx, dy);
//                 }
//             }
//         }
//     }
// };


