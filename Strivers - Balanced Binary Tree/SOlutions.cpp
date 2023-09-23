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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        if (std::abs(leftHeight - rightHeight) > 1) {
            return false;
        }
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        
        return std::max(leftHeight, rightHeight) + 1;
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
    
    // Call the isBalanced function and print the result
    bool balanced = solution.isBalanced(root);
    std::cout << "Is the binary tree balanced? " << (balanced ? "Yes" : "No") << std::endl;
    
    // Clean up the memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;
    
    return 0;
}



// #include <iostream>
// #include <algorithm>

// // Definition for a binary tree node
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
// };

// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         if (root == nullptr) {
//             return true;
//         }
        
//         int leftHeight = getHeight(root->left);
//         int rightHeight = getHeight(root->right);
        
//         if (std::abs(leftHeight - rightHeight) > 1) {
//             return false;
//         }
        
//         return isBalanced(root->left) && isBalanced(root->right);
//     }
    
// private:
//     int getHeight(TreeNode* node) {
//         if (node == nullptr) {
//             return 0;
//         }
        
//         int leftHeight = getHeight(node->left);
//         int rightHeight = getHeight(node->right);
        
//         return std::max(leftHeight, rightHeight) + 1;
//     }
// };

// int main() {
//     // Create the binary tree
//     TreeNode* root = new TreeNode(3);
//     root->left = new TreeNode(9);
//     root->right = new TreeNode(20);
//     root->right->left = new TreeNode(15);
//     root->right->right = new TreeNode(7);
    
//     // Create an instance of the Solution class
//     Solution solution;
    
//     // Call the isBalanced function and print the result
//     bool balanced = solution.isBalanced(root);
//     std::cout << "Is the binary tree balanced? " << (balanced ? "Yes" : "No") << std::endl;
    
//     // Clean up the memory
//     delete root->right->right;
//     delete root->right->left;
//     delete root->right;
//     delete root->left;
//     delete root;
    
//     return 0;
// }
