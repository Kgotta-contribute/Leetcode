#include <iostream>
#include <algorithm>

// Definition for a binary tree node
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        return std::max(leftDepth, rightDepth) + 1;
    }
};

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    // Create an instance of the Solution class
    Solution solution;
    
    // Call the maxDepth function and print the result
    int depth = solution.maxDepth(root);
    std::cout << "Maximum depth of the binary tree: " << depth << std::endl;
    
    // Clean up the memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;
    
    return 0;
}
