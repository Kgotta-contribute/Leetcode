#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Initialize arrays to keep track of numbers used in each row, column, and sub-box.
        bool rowUsed[9][9] = {false};
        bool colUsed[9][9] = {false};
        bool boxUsed[9][9] = {false};

        // Iterate through each cell in the Sudoku board.
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                // Check if the cell contains a digit (not a '.').
                if (board[i][j] != '.') {
                    // Convert the character to an integer (digit).
                    int digit = board[i][j] - '1';

                    // Check if the digit is already present in the same row.
                    if (rowUsed[i][digit]) {
                        return false;
                    }
                    // Mark the digit as used in the current row.
                    rowUsed[i][digit] = true;

                    // Check if the digit is already present in the same column.
                    if (colUsed[j][digit]) {
                        return false;
                    }
                    // Mark the digit as used in the current column.
                    colUsed[j][digit] = true;

                    // Check if the digit is already present in the same sub-box (3x3 grid).
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    if (boxUsed[boxIndex][digit]) {
                        return false;
                    }
                    // Mark the digit as used in the current sub-box.
                    boxUsed[boxIndex][digit] = true;
                }
            }
        }

        // If all checks pass, the Sudoku board is valid.
        return true;
    }
};

// Example input:
// Let's say we have the following Sudoku board (0-based indices):
// [["5","3",".",".","7",".",".",".","."],
//  ["6",".",".","1","9","5",".",".","."],
//  [".","9","8",".",".",".",".","6","."],
//  ["8",".",".",".","6",".",".",".","3"],
//  ["4",".",".","8",".","3",".",".","1"],
//  ["7",".",".",".","2",".",".",".","6"],
//  [".","6",".",".",".",".","2","8","."],
//  [".",".",".","4","1","9",".",".","5"],
//  [".",".",".",".","8",".",".","7","9"]]

// Explanation of the code execution:
// Iteration 1: Check row, column, and sub-box constraints for the digit "5" in cell (0,0).
// Iteration 2: Check row, column, and sub-box constraints for the digit "3" in cell (0,1).
// ... (and so on for each cell)
// Iteration 81: Check row, column, and sub-box constraints for the digit "9" in cell (8,8).
// If all checks pass for each iteration, the Sudoku board is valid.
