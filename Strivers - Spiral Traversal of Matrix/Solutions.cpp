#include <iostream>
#include <vector>

using namespace std;

void spiralTraversal(const vector<vector<int>>& matrix) 
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    int direction = 0;

    while (top <= bottom && left <= right) 
    {
        if (direction == 0) 
        { // Traverse from left to right
            for (int i = left; i <= right; i++) 
            {
                cout << matrix[top][i] << " ";
            }
            top++;
        } 
        else if (direction == 1) 
        { // Traverse from top to bottom
            for (int i = top; i <= bottom; i++) 
            {
                cout << matrix[i][right] << " ";
            }
            right--;
        } 
        else if (direction == 2) 
        { // Traverse from right to left
            for (int i = right; i >= left; i--) 
            {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        } 
        else if (direction == 3) 
        { // Traverse from bottom to top
            for (int i = bottom; i >= top; i--) 
            {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
        direction = (direction + 1) % 4;
    }
}
int main() {
    // Example 1
    vector<vector<int>> example1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    cout << "Example 1 Output: ";
    spiralTraversal(example1);
    cout << endl;

    // Example 2
    vector<vector<int>> example2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "Example 2 Output: ";
    spiralTraversal(example2);
    cout << endl;

    return 0;
}
