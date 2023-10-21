#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        // Calculate prefix products and store them in the result vector.
        int prefixProduct = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefixProduct;
            prefixProduct *= nums[i];
        }
        
        // Calculate suffix products and combine them with prefix products.
        int suffixProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffixProduct;
            suffixProduct *= nums[i];
        }
        
        return result;
    }
};

int main() {
    // Example usage:
    vector<int> nums = {1, 2, 3, 4};
    Solution solution;
    vector<int> result = solution.productExceptSelf(nums);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
