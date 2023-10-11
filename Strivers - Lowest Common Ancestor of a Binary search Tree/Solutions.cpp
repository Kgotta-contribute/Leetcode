/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return nullptr; // If the tree is empty, return nullptr.
        }
        
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q); // Both nodes are in the left subtree.
        } else if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q); // Both nodes are in the right subtree.
        } else {
            return root; // Current node is the LCA.
        }
    }
};
