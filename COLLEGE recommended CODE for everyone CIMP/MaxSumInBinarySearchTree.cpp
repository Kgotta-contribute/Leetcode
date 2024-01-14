#include <climits>
#include <algorithm>

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
**/

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        int prevVal = INT_MIN; 

        inorderTraversal(root, maxSum, prevVal);

        return maxSum;
    }

private:
    bool inorderTraversal(TreeNode* root, int& maxSum, int& prevVal) {
        if (!root) {
            return true;
        }

        // Traverse left subtree
        if (!inorderTraversal(root->left, maxSum, prevVal)) {
            return false;
        }

        // Check if the current node is part of a valid BST
        if (root->val > prevVal) {
            prevVal = root->val;
        } else {
            return false;
        }

        // Update maxSum with the current node's value
        maxSum += root->val;

        // Traverse right subtree
        return inorderTraversal(root->right, maxSum, prevVal);
    }
};
