// JAVA
class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        
        boolean firstRowZero = false;
        boolean firstColZero = false;
        
        // Check if the first row needs to be zeroed
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }
        
        // Check if the first column needs to be zeroed
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }
        
        // Use the first row and column to mark zeros in the matrix
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Zero out cells based on marks in the first row and column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Zero out the first row if needed
        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        
        // Zero out the first column if needed
        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }

    // Helper function to print the matrix
    private static void printMatrix(int[][] matrix) {
        for (int[] row : matrix) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        
        int[][] matrix1 = {
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1}
        };
        System.out.println("Input Matrix 1:");
        printMatrix(matrix1);

        sol.setZeroes(matrix1);

        System.out.println("\nOutput Matrix 1:");
        printMatrix(matrix1);

        int[][] matrix2 = {
            {0, 1, 2, 0},
            {3, 4, 5, 2},
            {1, 3, 1, 5}
        };
        System.out.println("\nInput Matrix 2:");
        printMatrix(matrix2);

        sol.setZeroes(matrix2);

        System.out.println("\nOutput Matrix 2:");
        printMatrix(matrix2);
    }
}





// CPP
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void setMatrixZero(vector<vector<int>>& matrix) 
{
    // gives the number of rows in the 2D matrix.
    int m = matrix.size();
    //store the number of columns in the matrix vector. Since the matrix is a 2D vector, 
    //matrix[0] gives the first row of the matrix, and matrix[0].size() returns the number of elements in that row, which is equal to the number of columns in the entire matrix.
    int n = matrix[0].size();
    //This declares two unordered sets named zeroRows and zeroCols. These sets will be used to store the row and column 
    //indices where a 0 element is found in the matrix, respectively. The use of an unordered set ensures that the indices are unique and won't have any duplicates.
    unordered_set<int> zeroRows, zeroCols;

    // Step 1: Find positions of 0 elements
    for (int i = 0; i < m; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            // Checks if the current element is zero.
            // If zero, adds the row index i to zeroRows and the column index j to zeroCols.
            if (matrix[i][j] == 0) 
            {
                zeroRows.insert(i); 
                zeroCols.insert(j); 
            }
        }
    }

    // Step 2: Set entire rows and columns to 0
    for (int i = 0; i < m; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            // Checks if the current row i or column j is in the sets zeroRows or zeroCols. If true, sets matrix[i][j] to 0.
            if (zeroRows.find(i) != zeroRows.end() || zeroCols.find(j) != zeroCols.end()) 
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// Function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) 
{
    for (const auto& row : matrix) 
    {
        for (int val : row) 
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix1 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    cout << "Input Matrix 1:" << endl;
    printMatrix(matrix1);

    setMatrixZero(matrix1);

    cout << "\nOutput Matrix 1:" << endl;
    printMatrix(matrix1);

    vector<vector<int>> matrix2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    cout << "\nInput Matrix 2:" << endl;
    printMatrix(matrix2);

    setMatrixZero(matrix2);

    cout << "\nOutput Matrix 2:" << endl;
    printMatrix(matrix2);

    return 0;
}




