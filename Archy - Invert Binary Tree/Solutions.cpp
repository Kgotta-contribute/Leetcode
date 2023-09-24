#include <iostream>
using namespace std;
// Definition for a binary tree node.
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
void printInOrder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    printInOrder(node->left);
    std::cout << node->val << " ";
    printInOrder(node->right);
}

int main() {
    Solution solution;

    // Create a sample binary tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // Invert the binary tree
    TreeNode* invertedRoot = solution.invertTree(root);

    // Print the inverted tree (in-order traversal)
    std::cout << "Inverted Tree (In-order): ";
    printInOrder(invertedRoot);
    std::cout << std::endl;

    return 0;
}



// Let's consider the initial binary tree:

//     4
//    / \
//   2   7
//  / \ / \
// 1  3 6  9
// Here's how the code progresses:

// Initial Call: invertTree(root) with root as the root of the tree (4).

// First Call (root=4):

// temp is assigned the value of root->right, which is 7.
// root->right is set to root->left, which is 2.
// root->left is set to temp, which is 7.
// The tree becomes:

//      4
//     / \
//    7   2
//   / \ / \
//  1  3 6  9
// Recursion is called on the left child (7): invertTree(root->left).
// Second Call (root=7):

// Since 7 is a leaf node, there's nothing to swap, and it returns immediately.
// The tree remains the same:

//      4
//     / \
//    7   2
//   / \ / \
//  1  3 6  9
// Recursion returns from the left child (7) to its parent (4).
// Third Call (root=2):

// temp is assigned the value of root->right, which is 3.
// root->right is set to root->left, which is 1.
// root->left is set to temp, which is 3.
// The tree becomes:

//      4
//     / \
//    7   2
//   / \ / \
//  1  3 6  9
// Recursion is called on the left child (3): invertTree(root->left).
// Fourth Call (root=3):

// Since 3 is a leaf node, there's nothing to swap, and it returns immediately.
// The tree remains the same:

//      4
//     / \
//    7   2
//   / \ / \
//  1  3 6  9
// Recursion returns from the left child (3) to its parent (2).
// Fifth Call (root=2):

// temp is assigned the value of root->right, which is 1 (previously swapped).
// root->right is set to root->left, which is 3 (previously swapped).
// root->left is set to temp, which is 1 (previously swapped).
// The tree becomes:

//      4
//     / \
//    7   2
//   / \ / \
//  1  3 6  9
// Recursion is called on the right child (1): invertTree(root->right).
// Sixth Call (root=1):

// Since 1 is a leaf node, there's nothing to swap, and it returns immediately.
// The tree remains the same:
//      4
//     / \
//    7   2
//   / \ / \
//  1  3 6  9
// Recursion returns from the right child (1) to its parent (2).
// Seventh Call (root=2):

// Recursion returns from the right child (1) to its parent (4).
// Eighth Call (root=4):

// Recursion returns from the left child (7) to its parent (4).
// The entire tree is now inverted:
//      4
//     / \
//    2   7
//   / \ / \
//  3  1 9  6