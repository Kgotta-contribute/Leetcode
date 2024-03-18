#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        // Sorting the balloons based on the end point
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1; // Initialize with 1 arrow for the first balloon
        int end = points[0][1];

        // Iterate through the balloons and count the arrows needed
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > end) {
                // Balloon cannot be burst by the current arrow, shoot a new arrow
                arrows++;
                end = points[i][1];
            }
            // If the current balloon is overlapped with the previous, continue with the same arrow
        }

        return arrows;
    }
};



===========================================================================================





// JAVA


import java.util.Arrays;

class Solution {
    public int findMinArrowShots(int[][] points) {
        if (points == null || points.length == 0) {
            return 0;
        }
        
        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1])); // sort by end points
        
        int arrows = 1; // initialize with one arrow for the first balloon
        int end = points[0][1];
        
        for (int i = 1; i < points.length; i++) {
            if (points[i][0] > end) {
                // balloon cannot be burst by current arrow, shoot a new arrow
                arrows++;
                end = points[i][1];
            }
            // if the current balloon is overlapped with the previous, continue with the same arrow
        }
        
        return arrows;
    }
}

// int[][] points1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
// System.out.println("Output for Example 1: " + new Solution().findMinArrowShots(points1));

// int[][] points2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
// System.out.println("Output for Example 2: " + new Solution().findMinArrowShots(points2));

// int[][] points3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
// System.out.println("Output for Example 3: " + new Solution().findMinArrowShots(points3));






======================================================================================================




/*
Consider a balloon with the point [xstart, xend]. In this case, a represents the first balloon [xstart1, xend1], 
and b represents the second balloon [xstart2, xend2] when comparing them during the sorting process.

The expression a[1] < b[1] compares the end points of the balloons:

If a[1] (end point of the first balloon) is less than b[1] (end point of the second balloon), 
the comparison evaluates to true.
If a[1] is greater than or equal to b[1], the comparison evaluates to false.
*/



// BELOW CODE HAS ONE MORE FUNCTION TO COMPARE & CODE IS MORE READABLE

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Custom comparison function to sort based on the end point
bool compareBalloons(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        // Sorting the balloons based on the end point using the custom comparison function
        sort(points.begin(), points.end(), compareBalloons);

        int arrows = 1; // Initialize with 1 arrow for the first balloon
        int end = points[0][1];

        // Iterate through the balloons and count the arrows needed
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > end) {
                // Balloon cannot be burst by the current arrow, shoot a new arrow
                arrows++;
                end = points[i][1];
            }
            // If the current balloon is overlapped with the previous, continue with the same arrow
        }

        return arrows;
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<vector<int>> points1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << "Output for Example 1: " << solution.findMinArrowShots(points1) << endl;

    vector<vector<int>> points2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cout << "Output for Example 2: " << solution.findMinArrowShots(points2) << endl;

    vector<vector<int>> points3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << "Output for Example 3: " << solution.findMinArrowShots(points3) << endl;

    return 0;
}

*/