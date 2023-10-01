#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr; // Base case, empty tree

        if (root->val == p->val || root->val == q->val) {
            // If the current node is equal to p or q, it's the common ancestor
            return root;
        }

        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        if (leftLCA && rightLCA) {
            // If p and q are found in different subtrees, the current node is the LCA
            return root;
        } else if (leftLCA) {
            // If only p or q is found in the left subtree
            return leftLCA;
        } else {
            // If only p or q is found in the right subtree
            return rightLCA;
        }
    }
};

int main() {
    // Create the example binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Nodes to find the lowest common ancestor for
    TreeNode* p = root->left;  // Node 5
    TreeNode* q = root->right->left;  // Node 0

    Solution solution;
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);

    std::cout << "Lowest Common Ancestor: " << lca->val << std::endl;

    // Clean up the memory (free the allocated nodes)
    // Implement your cleanup logic based on your specific use case

    return 0;
}
