#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    int n = nums.size();

    for (int a = 0; a < n - 3; ++a) {
        for (int b = a + 1; b < n - 2; ++b) {
            for (int c = b + 1; c < n - 1; ++c) {
                for (int d = c + 1; d < n; ++d) {
                    if (nums[a] + nums[b] + nums[c] + nums[d] == target) {
                        result.push_back({nums[a], nums[b], nums[c], nums[d]});
                    }
                }
            }
        }
    }

    // Remove duplicates from the result
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());

    return result;
}

int main() {
    vector<int> arr1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    vector<vector<int>> result1 = fourSum(arr1, target1);
    cout << "Result for Example 1:" << endl;
    for (const auto& quad : result1) {
        for (int num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }

    vector<int> arr2 = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target2 = 9;
    vector<vector<int>> result2 = fourSum(arr2, target2);
    cout << "\nResult for Example 2:" << endl;
    for (const auto& quad : result2) {
        for (int num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}







