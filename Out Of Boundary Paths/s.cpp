// HARD

class Solution {

public:

    int findPaths(int m, int n, int N, int x, int y) {
        const int M = 1000000000 + 7;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[x][y] = 1;
        int count = 0;
        for (int moves = 1; moves <= N; moves++) {
            vector<vector<int>> temp(m, vector<int>(n, 0));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == m - 1) count = (count + dp[i][j]) % M;
                    if (j == n - 1) count = (count + dp[i][j]) % M;
                    if (i == 0) count = (count + dp[i][j]) % M;
                    if (j == 0) count = (count + dp[i][j]) % M;
                    temp[i][j] = (
                        ((i > 0 ? dp[i - 1][j] : 0) + (i < m - 1 ? dp[i + 1][j] : 0)) % M +
                        ((j > 0 ? dp[i][j - 1] : 0) + (j < n - 1 ? dp[i][j + 1] : 0)) % M
                    ) % M;
                }
            }
            dp = temp;
        }
        return count;
    }
};


/*

int m = 2, n = 2, N = 2, x = 0, y = 0;
// Example input: m = 2, n = 2, N = 2, x = 0, y = 0

int result = solution.findPaths(m, n, N, x, y);
// Result: The number of paths to move out of the grid in N moves starting from position (x, y).

// Iterations:
// Initial dp matrix:
// [[1, 0],
//  [0, 0]]

// After 1 move:
// [[2, 0],
//  [0, 2]]
// Count: 4 (each boundary cell contributes 1)

// After 2 moves:
// [[4, 0],
//  [0, 4]]
// Count: 8 (each boundary cell contributes 2)

// Result: Total count of paths after 2 moves from the starting position (0, 0) in a 2x2 grid.
// Output: 8

Explanation:

1. The `findPaths` function initializes a dynamic programming matrix `dp` with dimensions `m x n`.
2. It iterates through the moves from 1 to `N`.
3. For each move, it calculates the next state using the `temp` matrix.
4. It updates the count based on the boundaries of the grid.
5. The final count is returned as the result.
*/




