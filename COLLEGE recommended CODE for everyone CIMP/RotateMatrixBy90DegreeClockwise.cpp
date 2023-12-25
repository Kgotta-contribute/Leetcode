#include <iostream>
#include <vector>

using namespace std;

void rotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; ++i) {
        int start = 0, end = n - 1;
        while (start < end) {
            swap(matrix[i][start], matrix[i][end]);
            ++start;
            --end;
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example 1
    vector<vector<int>> matrix1 = {{1, 2, 3},
                                   {4, 5, 6},
                                   {7, 8, 9}};
    
    cout << "Original Matrix 1:\n";
    printMatrix(matrix1);

    rotateMatrix(matrix1);

    cout << "\nRotated Matrix 1:\n";
    printMatrix(matrix1);

    // Example 2
    vector<vector<int>> matrix2 = {{1, 2},
                                   {3, 4}};

    cout << "\nOriginal Matrix 2:\n";
    printMatrix(matrix2);

    rotateMatrix(matrix2);

    cout << "\nRotated Matrix 2:\n";
    printMatrix(matrix2);

    return 0;
}
