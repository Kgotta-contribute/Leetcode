#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Transposing the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reversing each row of the matrix
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
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
    vector<vector<int>> example1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Example 1 Input:" << endl;
    printMatrix(example1);
    rotate(example1);
    cout << "Example 1 Output:" << endl;
    printMatrix(example1);

    // Example 2
    vector<vector<int>> example2 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };
    cout << "Example 2 Input:" << endl;
    printMatrix(example2);
    rotate(example2);
    cout << "Example 2 Output:" << endl;
    printMatrix(example2);

    return 0;
}



/*
Now, let's go through the iteration of the rotate function with the example matrix.

int n = matrix.size();
Here, n will be 3 since the input matrix has three rows (or columns, as it's a square matrix).

Transposing the matrix:

Iteration 1 (i = 0):

j = 0: No action because i and j are the same.
j = 1: Swap matrix[0][1] (2) with matrix[1][0] (4).
j = 2: Swap matrix[0][2] (3) with matrix[2][0] (7).
Matrix after this iteration: [[1, 4, 7], [2, 5, 6], [3, 8, 9]]
Iteration 2 (i = 1):

j = 0: No action because i and j are the same.
j = 1: No action because i and j are the same.
j = 2: Swap matrix[1][2] (6) with matrix[2][1] (8).
Matrix after this iteration: [[1, 4, 7], [2, 5, 8], [3, 6, 9]]
Iteration 3 (i = 2):

j = 0: No action because i and j are the same.
j = 1: No action because i and j are the same.
j = 2: No action because i and j are the same.
Matrix after this iteration: [[1, 4, 7], [2, 5, 8], [3, 6, 9]]
Reversing each row of the matrix:

Row 0: Reverse the elements: [7, 4, 1]
Row 1: Reverse the elements: [8, 5, 2]
Row 2: Reverse the elements: [9, 6, 3]
Matrix after this step: [[7, 4, 1], [8, 5, 2], [9, 6, 3]]
Finally, the rotated matrix is: [[7, 4, 1], [8, 5, 2], [9, 6, 3]]
*/