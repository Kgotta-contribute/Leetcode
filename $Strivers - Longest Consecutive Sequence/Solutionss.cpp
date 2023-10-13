
#include <iostream>
#include<vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;
        for (int num : numSet) {
            // If the current number is the start of a sequence, count the length
            // Check if the current number is the start of a sequence (i.e., num-1 is not present in the set)
            //If num - 1 is not found, it means that the current number 
            //is the start of a new sequence.
            //If num - 1 is found in the set, it implies that the current number is part of an existing sequence, 
            //and we skip processing it further as it is not the start of a new sequence.
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentLen = 1;
                // Increment currentNum to find the end of the sequence
                // Find the length of the con sequence starting from the current number
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentLen++;
                }
                maxLen = max(maxLen, currentLen);
            }
        }
        return maxLen;
    }
};

int main() {
    vector<int> nums = {100, 200, 1, 2, 3, 4};
    Solution solution;
    int maxLen = solution.longestConsecutive(nums);
    cout << "The longest consecutive sequence is " << maxLen << endl;
    return 0;
}


//  OR



// #include <iostream>
// #include <vector>
// #include <unordered_set>
// using namespace std;

// int longestConSequence(const vector<int>& nums) {
//     int n = nums.size();
//     if (n <= 1)
//         return n;
//     unordered_set<int> numSet(nums.begin(), nums.end());
//     int maxLen = 0;

//     for (int num : nums) {
//         // Check if the current number is the start of a sequence (i.e., num-1 is not present in the set)
//         //If num - 1 is not found (i.e., it is not present in the set), it means that the current number is the start of a new sequence. 
//         //If num - 1 is found in the set, it implies that the current number is part of an existing sequence, and we skip processing it further as it is not the start of a new sequence.
//         if (numSet.find(num - 1) == numSet.end()) {
//             int currentNum = num;
//             int currentLen = 1;

//             // Find the length of the con sequence starting from the current number
//             while (numSet.find(currentNum + 1) != numSet.end()) {
//                 currentNum++;
//                 currentLen++;
//             }

//             maxLen = max(maxLen, currentLen);
//         }
//     }

//     return maxLen;
// }

// int main() {
//     vector<int> nums1 = {7,8,9,10,11,100, 200, 1, 3, 2, 4,5,6};
//     cout << "Example 1: " << longestConSequence(nums1) << endl;

//     vector<int> nums2 = {3, 8, 5, 7, 6};
//     cout << "Example 2: " << longestConSequence(nums2) << endl;

//     return 0;
// }






// #include<bits/stdc++.h>
// using namespace std;
// int longestConsecutive(vector<int> nums) {
//         if(nums.size() == 0 ){
//             return 0;
//         }
        
//         sort(nums.begin(),nums.end());
        
//         int ans = 1;
//         int prev = nums[0];
//         int cur = 1;
        
//         for(int i = 1;i < nums.size();i++){
//             if(nums[i] == prev+1){
//                 cur++;
//             }
//             else if(nums[i] != prev){
//                 cur = 1;
//             }
//             prev = nums[i];
//             ans = max(ans, cur);
//         }
//         return ans;
//     }
//     // int main()
//     // {
//     //     vector<int> arr{100,200,1,2,3,4};
//     //     int lon=longestConsecutive(arr);
//     //     cout<<"The longest consecutive sequence is "<<lon<<endl;
        
//     // }

