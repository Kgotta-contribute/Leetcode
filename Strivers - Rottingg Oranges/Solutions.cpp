class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        int minutes = 0;
        queue<pair<int, int>> rotten;

        // Define 4 directions (right, left, down, up) as dx and dy arrays
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        // Count the number of fresh oranges and add rotten oranges to the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    rotten.push({i, j});
                }
            }
        }

        while (!rotten.empty() && fresh > 0) {
            int size = rotten.size();
            for (int i = 0; i < size; i++) {
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();

                for (int k = 0; k < 4; k++) {
                    int newX = x + dx[k];
                    int newY = y + dy[k];

                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2; // Mark the orange as rotten
                        rotten.push({newX, newY});
                        fresh--;
                    }
                }
            }
            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
