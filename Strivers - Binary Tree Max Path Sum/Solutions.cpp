#include <iostream>
#include <algorithm>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }

    int maxPathSumHelper(TreeNode* node, int& maxSum) {
        if (node == nullptr) {
            return 0;
        }

        int leftSum = std::max(0, maxPathSumHelper(node->left, maxSum));
        int rightSum = std::max(0, maxPathSumHelper(node->right, maxSum));

        int currentSum = node->val + leftSum + rightSum;
        maxSum = std::max(maxSum, currentSum);

        return node->val + std::max(leftSum, rightSum);
    }
};

int main() {
    Solution solution;

    // Create the binary tree
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Calculate the maximum path sum
    int maxSum = solution.maxPathSum(root);

    // Print the result
    std::cout << "Maximum Path Sum: " << maxSum << std::endl;

    // Clean up the memory
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
