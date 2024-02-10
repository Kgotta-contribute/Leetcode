// LITTLE WEIRD - AS WE'RE TRYING TO CREATE A BINARY TREE USING THIS FUNCTION : createBST
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDiff = INT_MAX;
    TreeNode* prev = nullptr;

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minDiff;
    }

    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        if (prev != nullptr) {
            minDiff = min(minDiff, root->val - prev->val);
        }
        prev = root;
        inorder(root->right);
    }
};

// Helper function to create a binary tree from given vector
TreeNode* createBST(vector<int>& nums, int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = createBST(nums, start, mid - 1);
    root->right = createBST(nums, mid + 1, end);
    return root;
}

int main() {
    Solution sol;
    vector<int> nums1 = {4, 2, 6, 1, 3};
    TreeNode* root1 = createBST(nums1, 0, nums1.size() - 1);
    cout << " 1: " << sol.getMinimumDifference(root1) << endl;

    vector<int> nums2 = {1, 0, 48, 12, 49};
    TreeNode* root2 = createBST(nums2, 0, nums2.size() - 1);
    cout << " 2: " << sol.getMinimumDifference(root2) << endl;

    return 0;
}
