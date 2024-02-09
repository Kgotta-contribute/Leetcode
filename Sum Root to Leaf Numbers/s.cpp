/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0;
        
        // Update the current sum by adding the current node's value
        currentSum = currentSum * 10 + node->val;// 49051 -> 4,49,495,491,40
        
        // If the node is a leaf node, return the current sum
        if (!node->left && !node->right) return currentSum;
        
        // Recursively calculate the sum for left and right subtrees
        int leftSum = dfs(node->left, currentSum);
        int rightSum = dfs(node->right, currentSum);
        // we will always calculate root to leaf path
        // Return the sum of sums from left and right subtrees
        return leftSum + rightSum;
    }
}; 