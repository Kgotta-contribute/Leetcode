// FELY HARD
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i< nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j< nums.size(); j++){
                if(j> i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1;
                int l = nums.size() - 1;
                while(k<l){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        vector <int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--;
                    }
                    else if(sum > target) l--;
                    else k++;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution solution;
    vector<vector<int>> result = solution.fourSum(nums, target);

    for (vector<int>& quad : result) {
        cout << "[";
        for (int i = 0; i < quad.size(); i++) {
            cout << quad[i];
            if (i < quad.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}







// sort(nums.begin(), nums.end()); - Sort the nums array: [-2, -2, -1, 0, 0, 1, 2, 2].

// Loop with i:

// i = 0: Check if(i > 0 && nums[i] == nums[i-1]) (False). Proceed.

// Nested loop with j:
// j = 1: Check if(j > i + 1 && nums[j] == nums[j-1]) (False). Proceed.

// Initialize k = 2 and l = 7.

// While loop (while(k < l)):

// Calculate sum = nums[i] + nums[j] + nums[k] + nums[l] (sum = 1 - 2 - 2 + 2 = -1).

// Since sum is less than the target (0), increment k to 3.

// Inside the while loop, continue iterating:

// Calculate sum (sum = 1 - 2 - 2 + 0 = -3).
// Increment k to 4.
// Continue iterating:

// Calculate sum (sum = 1 - 2 - 2 - 1 = -4).
// Increment k to 5.
// k and l pointers meet (k >= l). End the while loop.

// No valid quadruplet found in this iteration of j.

// j = 2: Check if(j > i + 1 && nums[j] == nums[j-1]) (False). Proceed.

// Initialize k = 3 and l = 7.

// While loop (while(k < l)):

// Calculate sum (sum = 1 - 2 - 2 + 2 = -1).

// Increment k to 4.

// k and l pointers meet (k >= l). End the while loop.

// No valid quadruplet found in this iteration of j.

// Continue iterating through j until the end.

// Continue iterating through i until the end.

// The function returns ans with the found unique quadruplets: [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]].

// Example 2:

// vector<vector<int>> fourSum(vector<int>& nums, int target) { - Function definition.

// vector<vector<int>> ans; - Initialize an empty vector ans to store quadruplets.

// sort(nums.begin(), nums.end()); - Sort the nums array: [2, 2, 2, 2, 2].

// Loop with i:

// i = 0: Check if(i > 0 && nums[i] == nums[i-1]) (False). Proceed.

// Nested loop with j:
// j = 1: Check if(j > i + 1 && nums[j] == nums[j-1]) (False). Proceed.

// Initialize k = 2 and l = 4.

// While loop (while(k < l)):

// Calculate sum (sum = 2 + 2 + 2 + 2 = 8).

// sum is equal to the target, so a valid quadruplet is found.

// Add [2, 2, 2, 2] to ans.

// Increment k to 3.

// k and l pointers meet (k >= l). End the while loop.

// Continue iterating through j until the end.

// Continue iterating through i until the end.

// The function returns ans with the found unique quadruplet: [[2, 2, 2, 2]].
