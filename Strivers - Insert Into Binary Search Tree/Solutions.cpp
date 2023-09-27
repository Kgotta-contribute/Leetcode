#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            // If the tree is empty, create a new node with the given value
            return new TreeNode(val);
        }
        
        // Insert the value recursively based on BST property
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        
        return root;
    }
};

// Function to print the tree in-order for testing purposes
void inOrderTraversal(TreeNode* root) {
    if (root) {
        inOrderTraversal(root->left);
        std::cout << root->val << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    // Create the BST as given in the example
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);

    // Insert a new value into the BST
    int val1 = 5;
    Solution solution1;
    TreeNode* result1 = solution1.insertIntoBST(root1, val1);

    // Print the in-order traversal of the resulting tree
    inOrderTraversal(result1);
    std::cout << std::endl;

    // Create the second BST as given in the example
    TreeNode* root2 = new TreeNode(40);
    root2->left = new TreeNode(20);
    root2->right = new TreeNode(60);
    root2->left->left = new TreeNode(10);
    root2->left->right = new TreeNode(30);
    root2->right->left = new TreeNode(50);
    root2->right->right = new TreeNode(70);

    // Insert a new value into the second BST
    int val2 = 25;
    Solution solution2;
    TreeNode* result2 = solution2.insertIntoBST(root2, val2);

    // Print the in-order traversal of the resulting tree
    inOrderTraversal(result2);
    std::cout << std::endl;

    // Clean up the memory by deleting the tree nodes (not shown in the original code)
    
    return 0;
}
