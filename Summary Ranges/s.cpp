#include <vector>
#include <string>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;

        for (int i = 0; i < nums.size(); ++i) { 
            // Input: nums = [0,1,2,4,5,7]   Output: ["0->2","4->5","7"]
            int start = nums[i]; // ITER 1 : 0    // ITER 2 : 4
            // Loop to check consecutive number
            while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1) { 
                // ITER 1 : 1 < 6 && 1 == 1 ; 2 < 6 && 2 == 2 ; 3 < 6 && 4 != 3
                // ITER 2 : 4 < 6 && 5 == 5 ; 5 < 6 && 5 != 6
                ++i;
            }
            int end = nums[i]; // ITER 1 : end = 2  // ITER 2 : end = 5

            if (start == end) {
                result.push_back(to_string(start));
            } else {
                result.push_back(to_string(start) + "->" + to_string(end)); // "0 -> 2"  ;   // "4->5"
            }
        }

        return result;
    }
};

/*
STEPS HERE : 
Initialize an empty vector of strings result.
Iterate through the input array nums.
For each element at index i, initialize start with the current element's value.
Use a while loop to find consecutive numbers, incrementing the index i.
After the while loop, set end to the last consecutive number found.
Check if start is equal to end. If true, push a single number string to result. Otherwise, push a range string to result.
Continue the loop until all elements are processed.
STEPS END :

// QUESTION : 
You are given a sorted unique integer array nums.
A range [a,b] is the set of all integers from a to b (inclusive).
Return the smallest sorted list of ranges that cover all the numbers in the array exactly. 
That is, each element of nums is covered by exactly one of the ranges, and there is no integer 
x such that x is in one of the ranges but not in nums.
Each range [a,b] in the list should be output as:
"a->b" if a != b
"a" if a == b
 
Example 1:
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

Example 2:
Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
*/