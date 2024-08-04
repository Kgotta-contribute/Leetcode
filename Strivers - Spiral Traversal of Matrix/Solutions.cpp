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





// JAVA

import java.util.ArrayList;
import java.util.List;

public class SpiralTraversal {
    public static void spiralTraversal(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;

        int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
        int direction = 0;

        while (top <= bottom && left <= right) {
            if (direction == 0) {
                // Traverse from left to right
                for (int i = left; i <= right; i++) {
                    System.out.print(matrix[top][i] + " ");
                }
                top++;
            } else if (direction == 1) {
                // Traverse from top to bottom
                for (int i = top; i <= bottom; i++) {
                    System.out.print(matrix[i][right] + " ");
                }
                right--;
            } else if (direction == 2) {
                // Traverse from right to left
                for (int i = right; i >= left; i--) {
                    System.out.print(matrix[bottom][i] + " ");
                }
                bottom--;
            } else if (direction == 3) {
                // Traverse from bottom to top
                for (int i = bottom; i >= top; i--) {
                    System.out.print(matrix[i][left] + " ");
                }
                left++;
            }
            direction = (direction + 1) % 4;
        }
    }

    public static void main(String[] args) {
        // Example 1
        int[][] example1 = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
        };
        System.out.print("Example 1 Output: ");
        spiralTraversal(example1);
        System.out.println();

        // Example 2
        int[][] example2 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        System.out.print("Example 2 Output: ");
        spiralTraversal(example2);
        System.out.println();
    }
}






// PYTHON 

def spiral_traversal(matrix):
    if not matrix:
        return

    rows = len(matrix)
    cols = len(matrix[0])

    top = 0
    bottom = rows - 1
    left = 0
    right = cols - 1
    direction = 0

    result = []

    while top <= bottom and left <= right:
        if direction == 0:  # Traverse from left to right
            for i in range(left, right + 1):
                result.append(matrix[top][i])
            top += 1
        elif direction == 1:  # Traverse from top to bottom
            for i in range(top, bottom + 1):
                result.append(matrix[i][right])
            right -= 1
        elif direction == 2:  # Traverse from right to left
            for i in range(right, left - 1, -1):
                result.append(matrix[bottom][i])
            bottom -= 1
        elif direction == 3:  # Traverse from bottom to top
            for i in range(bottom, top - 1, -1):
                result.append(matrix[i][left])
            left += 1
        direction = (direction + 1) % 4

    print(" ".join(map(str, result)))


def main():
    # Example 1
    example1 = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12],
        [13, 14, 15, 16]
    ]
    print("Example 1 Output:", end=" ")
    spiral_traversal(example1)

    # Example 2
    example2 = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    print("Example 2 Output:", end=" ")
    spiral_traversal(example2)


if __name__ == "__main__":
    main()
