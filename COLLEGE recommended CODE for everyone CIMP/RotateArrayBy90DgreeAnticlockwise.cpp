#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row of the transposed matrix
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
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example 1
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotateMatrix(matrix1);

    cout << "Rotated Matrix 1:" << endl;
    printMatrix(matrix1);

    // Example 2
    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    rotateMatrix(matrix2);

    cout << "Rotated Matrix 2:" << endl;
    printMatrix(matrix2);

    return 0;
}
