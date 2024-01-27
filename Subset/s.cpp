#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;

        result.push_back({});
        for (int i = 0; i < nums.size(); ++i) {
            int size = result.size();
            for (int j = 0; j < size; ++j) {
                vector<int> subset = result[j];
                subset.push_back(nums[i]);
                result.push_back(subset);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Subsets for [1, 2, 3]
    vector<int> nums1 = {1, 2, 3};
    vector<vector<int>> result1 = solution.subsets(nums1);

    // Print the subsets for [1, 2, 3]
    cout << "Subsets for [1, 2, 3]:\n";
    for (const auto& subset : result1) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}



======================================================================



#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        generateSubsets(nums, 0, current, result);
        return result;
    }

private:
    void generateSubsets(const vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        
        result.push_back(current);

        for (int i = index; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            generateSubsets(nums, i + 1, current, result);
            current.pop_back();
        }
    }
};

int main() {
    Solution solution;
    
    //  1
    vector<int> nums1 = {1, 2, 3};
    vector<vector<int>> result1 = solution.subsets(nums1);

    //  2
    vector<int> nums2 = {0};
    vector<vector<int>> result2 = solution.subsets(nums2);

    return 0;
}