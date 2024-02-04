// NICE CODE -> one is 2d array & 2nd is 2d array
#include <vector>

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n = intervals.size();
        int i = 0;

        // Add intervals that come before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i++]);
        }

        // Merge overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {        // 1 < 5   when 6 < 5 then loop exists
            newInterval[0] = min(newInterval[0], intervals[i][0]); // [1, ]
            newInterval[1] = max(newInterval[1], intervals[i++][1]); // [ ,5]   => [1,5] then i++ ie. i = 1 
        }

        // Add the merged newInterval
        result.push_back(newInterval);      // [1,5]

        // Add intervals that come after newInterval
        while (i < n) {
            result.push_back(intervals[i++]);       // [6,9]
        }

        return result; // [1,5],[6,9]
    }
};

/*
Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
*/