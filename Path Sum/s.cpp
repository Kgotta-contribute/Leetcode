#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: If the root is nullptr, return false
        if (root == nullptr)
            return false;
        // If the current node is a leaf node and its value equals the remaining target sum,
        // return true
        if (root->left == nullptr && root->right == nullptr && targetSum - root->val == 0)
            return true;
        // Recursively check the left and right subtrees with the updated target sum
        return hasPathSum(root->left, targetSum - root->val) || 
               hasPathSum(root->right, targetSum - root->val);
               
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    Solution solution;
    if (solution.hasPathSum(root, targetSum))
        cout << "Path with sum " << targetSum << " exists." << endl;
    else
        cout << "Path with sum " << targetSum << " does not exist." << endl;

    return 0;
}
