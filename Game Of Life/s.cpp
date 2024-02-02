#include <vector>

class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Define the eight possible directions to check neighbors
        std::vector<int> directions = {-1, 0, 1};

        // Helper function to check if a cell is valid and alive
        auto isValidAndAlive = [&](int i, int j) {
            return i >= 0 && i < m && j >= 0 && j < n && (board[i][j] == 1 || board[i][j] == -1);
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int liveNeighbors = 0;

                // Check all eight neighbors
                for (int dx : directions) {
                    for (int dy : directions) {
                        if (dx == 0 && dy == 0) continue; // Skip the cell itself

                        int ni = i + dx;
                        int nj = j + dy;

                        // Check if the neighbor is valid and alive
                        if (isValidAndAlive(ni, nj)) {
                            liveNeighbors++;
                        }
                    }
                }

                // Apply the rules of the Game of Life
                if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[i][j] = -1; // Mark cell as going to be dead
                }
                if (board[i][j] == 0 && liveNeighbors == 3) {
                    board[i][j] = 2; // Mark cell as going to be alive
                }
            }
        }

        // Update the board in-place
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == -1) {
                    board[i][j] = 0; // Dead
                } else if (board[i][j] == 2) {
                    board[i][j] = 1; // Alive
                }
            }
        }
    }
};