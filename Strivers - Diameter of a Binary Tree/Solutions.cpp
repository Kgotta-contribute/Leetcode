#include <iostream>

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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        calculateDiameter(root, diameter);
        return diameter;
    }

    int calculateDiameter(TreeNode* node, int& diameter) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = calculateDiameter(node->left, diameter);
        int rightHeight = calculateDiameter(node->right, diameter);

        diameter = std::max(diameter, leftHeight + rightHeight);

        return std::max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Create an instance of the Solution class
    Solution solution;

    // Calculate the diameter of the binary tree
    int diameter = solution.diameterOfBinaryTree(root);

    // Print the result
    std::cout << "Diameter of the binary tree: " << diameter << std::endl;

    // Clean up the memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
