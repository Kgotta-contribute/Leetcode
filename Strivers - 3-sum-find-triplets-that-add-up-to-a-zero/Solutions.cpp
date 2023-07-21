#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    result.push_back(triplet);
                }
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<int> nums2 = {-1, 0, 1, 0};

    vector<vector<int>> result1 = threeSum(nums1);
    vector<vector<int>> result2 = threeSum(nums2);

    // Output the results
    cout << "Example 1 Output:" << endl;
    for (const auto& triplet : result1) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }

    cout << "Example 2 Output:" << endl;
    for (const auto& triplet : result2) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }

    return 0;
}

