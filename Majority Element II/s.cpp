
#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;

        if (nums.empty()) {
            return result;
        }

        unordered_map<int, int> counts;

        // Count the occurrences of each element
        for (int num : nums) {
            counts[num]++;
        }

        // Check for majority elements
        for (const auto& entry : counts) {
            if (entry.second > nums.size() / 3) {
                result.push_back(entry.first);
            }
        }

        return result;
    }
};



int main() {
    Solution solution;
    
    // Example 1
    vector<int> nums1 = {3, 2, 3};
    vector<int> result1 = solution.majorityElement(nums1);
    cout << "Output for Example 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Example 2
    vector<int> nums2 = {1};
    vector<int> result2 = solution.majorityElement(nums2);
    cout << "Output for Example 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    // Example 3
    vector<int> nums3 = {1, 2};
    vector<int> result3 = solution.majorityElement(nums3);
    cout << "Output for Example 3: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}



/*
for (const auto& entry : counts) {

auto: In C++, auto is used for automatic type inference. Here, it is used to automatically deduce the type of the elements in the counts map, making it convenient and flexible.
const: This keyword indicates that the loop variable entry is constant and cannot be modified within the loop.
&: This ampersand (&) is used to create a reference to each element in the map. Using a reference allows the loop to work directly with the elements in the map without making unnecessary copies.
if (entry.second > nums.size() / 3) {

entry: Represents each key-value pair in the counts map during each iteration of the loop.
entry.second: Refers to the value associated with the key in the map, which is the count of occurrences of that element in the nums vector.
nums.size() / 3: The condition checks whether the count of occurrences (entry.second) is greater than one-third of the total size of the nums vector. 
*/