#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        
        sort(intervals.begin(), intervals.end());
        
        vector<int> current_interval = intervals[0];
        
        for (int i = 1; i < intervals.size(); i++) {
            // Check if the current interval overlaps with the next interval
            if (current_interval[1] >= intervals[i][0]) {
                // Merge the intervals
                current_interval[1] = max(current_interval[1], intervals[i][1]);
            } else {
                // If no overlap, add the current interval to the result and update current_interval
                merged.push_back(current_interval);
                current_interval = intervals[i];
            }
        }
        
        // Add the last merged or current interval to the result
        merged.push_back(current_interval);
        
        return merged;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    
    Solution solution;
    vector<vector<int>> merged_intervals = solution.merge(intervals);
    
    for (const vector<int>& interval : merged_intervals) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    
    return 0;
}


// Initial State:

// merged is an empty vector.
// intervals is sorted: {{1,3},{2,6},{8,10},{15,18}}.
// current_interval is initialized with {1,3}.
// Iterations:

// i = 1

// Check if {1,3} overlaps with {2,6}: Yes, they overlap.
// Merge them to get current_interval = {1,6}.
// i = 2

// Check if {1,6} overlaps with {8,10}: No, they don't overlap.
// Add {1,6} to merged.
// Update current_interval to {8,10}.
// i = 3

// Check if {8,10} overlaps with {15,18}: No, they don't overlap.
// Add {8,10} to merged.
// Update current_interval to {15,18}.
// i = 4 (End of loop)

// The loop ends because i reaches the end of intervals.
// Add the last current_interval, which is {15,18}, to merged.
// After Iterations:

// merged contains {1,6}, {8,10}, {15,18}.
// Output:

// The code prints the merged intervals as [1,6] [8,10] [15,18].
