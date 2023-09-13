#include <vector>
#include<iostream>
using namespace std; // Added using namespace std to remove std:: prefixes

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor == color) {
            return image;
        }

        dfs(image, sr, sc, originalColor, color);

        return image;
    }

    void dfs(vector<vector<int>>& image, int row, int col, int originalColor, int newColor) {
        if (row < 0 || row >= image.size() || col < 0 || col >= image[0].size() || image[row][col] != originalColor) {
            return;
        }

        image[row][col] = newColor;

        dfs(image, row + 1, col, originalColor, newColor);//  (moving down)
        dfs(image, row - 1, col, originalColor, newColor);//  (moving up)
        dfs(image, row, col + 1, originalColor, newColor);//  (moving right)
        dfs(image, row, col - 1, originalColor, newColor);//  (moving left)
    }
};

int main() {
    Solution solution;
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1;
    int sc = 1;
    int color = 2;

    vector<vector<int>> result = solution.floodFill(image, sr, sc, color);

    // Print the modified image
    for (const vector<int>& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}


// Let's say we have the following image:

// image = [
//   [1, 1, 1],
//   [1, 1, 0],
//   [1, 0, 1]
// ]
// And we want to perform a flood fill starting from (1, 1) with the newColor of 2.

// Initial setup:

// originalColor is set to image[1][1], which is 1.
// We call the dfs function with x = 1, y = 1, originalColor = 1, and newColor = 2.

// Inside dfs, we check if (1, 1) is out of bounds or if the pixel color is different from the originalColor. 
//In this case, (1, 1) is not out of bounds, and the color is the same, so we continue.

// We change the color of (1, 1) to 2.

// We recursively call dfs for neighboring pixels:

// dfs(image, 2, 1, 1, 2) (Down)
// dfs(image, 0, 1, 1, 2) (Up)
// dfs(image, 1, 0, 1, 2) (Left)
// dfs(image, 1, 2, 1, 2) (Right)
// For each of these calls, we check if the neighboring pixel is out of bounds or has a different color. If not, we change its color to 2 and continue recursively.

// The recursion continues for all valid neighboring pixels until there are no more pixels to process.

// After the flood fill is complete, the image is modified as follows:

// image = [
//   [2, 2, 2],
//   [2, 2, 0],
//   [2, 0, 1]
// ]
// This is the final state of the image after the flood fill operation. All pixels connected to the starting pixel (1, 1) with the original color 1 have been changed to the new color 2.