#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr; // Base case, empty tree
        
        if (p->val < root->val && q->val < root->val) {
            // Both p and q are in the left subtree
            return lowestCommonAncestor(root->left, p, q);
        } else if (p->val > root->val && q->val > root->val) {
            // Both p and q are in the right subtree
            return lowestCommonAncestor(root->right, p, q);
        } else {
            // One node is in the left subtree, and the other is in the right subtree,
            // or one of them is equal to the current node (ancestor found)
            return root;
        }
    }
};

int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    
    Solution solution;
    
    // Find LCA of nodes 2 and 8
    TreeNode* p = root->left->left;
    TreeNode* q = root->right->right;
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
    
    if (lca) {
        std::cout << "The lowest common ancestor is: " << lca->val << std::endl;
    } else {
        std::cout << "No common ancestor found." << std::endl;
    }
    
    // Clean up memory (optional)
    // Implement a function to delete the tree nodes recursively if needed.
    
    return 0;
}




//     6
//    / \
//   2   8
//  / \   \
// 0   4   9
//    / \
//   3   5
// We set p = 2 (node no. 2), and q = 8(node no. 8).

// We call lowestCommonAncestor with root of the tree, p= first node, and q = second node.

// root node = 6. Since p (2) < root (6) and q (8) > root, we enter the else block.

// Function returns root (6) as the lowest common ancestor because it's the first node encountered that is between p and q inclusive.

// In the main function, we print "The lowest common ancestor is: 6" as the result.