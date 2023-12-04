#include <iostream>
#include <algorithm> // for max function
#include<bits/stdc++.h>
using namespace std;

// HEIGHT OF LEFT SUBTREE - RIGHT SUBTREE <= 1 ;       // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left; TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        int height = 0; // Variable to store the height difference
        return isBalancedHelper(root, height);
    }
    bool isBalancedHelper(TreeNode* root, int& height)
    {
        if (root == nullptr)
        {
            height = 0; // Height of an empty tree is 0
            return true;
        }
        int leftHeight = 0, rightHeight = 0;
        // Check if the left subtree is balanced
        bool leftBalanced = isBalancedHelper(root->left, leftHeight);
        if (!leftBalanced)
        {
            return false; // Left subtree is unbalanced, no need to continue
        }
        // Check if the right subtree is balanced
        bool rightBalanced = isBalancedHelper(root->right, rightHeight);
        if (!rightBalanced)
        {
            return false; // Right subtree is unbalanced, no need to continue
        }
        // Calculate the height of the current node's subtree
        height = 1 + max(leftHeight, rightHeight);
        // Check if the current node is balanced
        if (abs(leftHeight - rightHeight) <= 1)
        {
            return true;
        }
        return false;
    }
};

int main() {
    Solution solution;

    // Example 1: Balanced tree
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    cout << "Example 1: " << (solution.isBalanced(root1) ? "True" : "False") << endl;

    // Example 2: Unbalanced tree
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);
    root2->left->left->right = new TreeNode(4);

    cout << "Example 2: " << (solution.isBalanced(root2) ? "True" : "False") << endl;

    // Example 3: Empty tree
    TreeNode* root3 = nullptr;

    cout << "Example 3: " << (solution.isBalanced(root3) ? "True" : "False") << endl;

    return 0;
}

/*
          1
    |           |
    2           2
|       |     |      |
3       3     4      4

*/

// Iteration 1:
// root points to node with value 1.
// Left subtree (root->left) is an empty tree.
// Right subtree (root->right) points to node with value 2.
// Iteration 1.1 (right subtree):
// root points to node with value 2.
// Left subtree (root->left) points to node with value 3.
// Right subtree (root->right) points to node with value 3.
// Iteration 1.1.1 (left subtree of right subtree):
// root points to node with value 3.
// Left subtree (root->left) points to node with value 4.
// Right subtree (root->right) points to node with value 4.
// Iteration 1.1.1.1 (left subtree of left subtree of right subtree):
// root points to node with value 4.
// Left subtree is an empty tree.
// Right subtree is an empty tree.
// The height of this subtree is 0.
// Iteration 1.1.1.2 (right subtree of left subtree of right subtree):
// root points to node with value 4.
// Left subtree is an empty tree.
// Right subtree is an empty tree.
// The height of this subtree is 0.

// Calculate the height of the current node's subtree: height = 1 + max(0, 0) = 1.
// Check if the current node is balanced: abs(0 - 0) <= 1, which is true.
// Calculate the height of the current node's subtree: height = 1 + max(1, 1) = 2.
// Check if the current node is balanced: abs(1 - 1) <= 1, which is true.
// Calculate the height of the current node's subtree: height = 1 + max(2, 2) = 3.
// Check if the current node is balanced: abs(2 - 2) <= 1, which is true.

// Iteration 2:
// root points to node with value 1.
// Left subtree (root->left) is an empty tree.
// Right subtree (root->right) points to node with value 2.
// Iteration 2.1 (right subtree):
// root points to node with value 2.
// Left subtree (root->left) points to node with value 3.
// Right subtree (root->right) points to node with value 3.
// ... (Same as Iteration 1.1)
// Calculate the height of the current node's subtree: height = 1 + max(3, 3) = 4.
// Check if the current node is balanced: abs(3 - 3) <= 1, which is true.
// Iteration 3:
// root points to node with value 1.
// Left subtree (root->left) is an empty tree.
// Right subtree (root->right) points to node with value 2.
// Iteration 3.1 (right subtree):
// root points to node with value 2.
// Left subtree (root->left) points to node with value 3.
// Right subtree (root->right) points to node with value 3.
// ... (Same as Iteration 1.1)
// Calculate the height of the current node's subtree: height = 1 + max(4, 4) = 5.
// Check if the current node is balanced: abs(4 - 4) <= 1, which is true.