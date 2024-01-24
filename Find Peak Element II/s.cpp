#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        int left = 0, right = col - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Find the maximum element in the mid column
            int maxRow = 0;
            for (int i = 1; i < row; ++i) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }
            
            // Check if the maximum element is a peak
            if ((mid == 0 || mat[maxRow][mid] > mat[maxRow][mid - 1]) &&
                (mid == col - 1 || mat[maxRow][mid] > mat[maxRow][mid + 1])) {
                return {maxRow, mid};
            } else if (mid > 0 && mat[maxRow][mid - 1] > mat[maxRow][mid]) {
                // If the element to the left is greater, search in the left half
                right = mid - 1;
            } else {
                // If the element to the right is greater, search in the right half
                left = mid + 1;
            }
        }
        
        // This should not happen as per the problem constraints
        return {-1, -1};
    }
};

