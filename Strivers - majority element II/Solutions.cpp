#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
        
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        // Reset counts for candidates to find their actual counts
        count1 = 0;
        count2 = 0;
        
        // Count occurrences of the two candidates
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            }
        }
        
        vector<int> result;
        
        if (count1 > nums.size() / 3) {
            result.push_back(candidate1);
        }
        if (count2 > nums.size() / 3) {
            result.push_back(candidate2);
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test the majorityElement function
    vector<int> nums = {3, 2, 3, 1, 2, 2, 3};
    vector<int> result = solution.majorityElement(nums);
    
    // Print the results
    cout << "Majority Elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
