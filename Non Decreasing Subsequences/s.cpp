// Out of L

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() >= 2) {
            result.push_back(current);
        }

        set<int> used;  // To handle duplicate elements in the same level
        for (int i = start; i < nums.size(); ++i) {
            if (!current.empty() && nums[i] < current.back()) {
                continue;  // Skip decreasing elements
            }

            if (used.count(nums[i])) {
                continue;  // Skip duplicate elements in the same level
            }

            used.insert(nums[i]);
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back();
        }
    }
};

int main() {
    Solution solution;
    
    //  1
    vector<int> nums1 = {4, 6, 7, 7};
    vector<vector<int>> result1 = solution.findSubsequences(nums1);
    cout << " 1 Output:" << endl;
    for (const auto& seq : result1) {
        for (int num : seq) {
            cout << num << " ";
        }
        cout << endl;
    }

    //  2
    vector<int> nums2 = {4, 4, 3, 2, 1};
    vector<vector<int>> result2 = solution.findSubsequences(nums2);
    cout << " 2 Output:" << endl;
    for (const auto& seq : result2) {
        for (int num : seq) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}



// method 2 


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        generateSubsequences(nums, 0, current, result);
        return result;
    }

private:
    void generateSubsequences(const vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() >= 2) {
            result.push_back(current);
        }

        for (int i = start; i < nums.size(); ++i) {
            if (current.empty() || nums[i] >= current.back()) {
                current.push_back(nums[i]);
                generateSubsequences(nums, i + 1, current, result);
                current.pop_back();
            }
        }
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {4, 6, 7, 7};
    vector<vector<int>> result1 = solution.findSubsequences(nums1);
    cout << "Example 1 Output:" << endl;
    for (const auto& seq : result1) {
        for (int num : seq) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Example 2
    vector<int> nums2 = {4, 4, 3, 2, 1};
    vector<vector<int>> result2 = solution.findSubsequences(nums2);
    cout << "Example 2 Output:" << endl;
    for (const auto& seq : result2) {
        for (int num : seq) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
