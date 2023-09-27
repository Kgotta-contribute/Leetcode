#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left) {
                return root->right;
            } else if (!root->right) {
                return root->left;
            }

            TreeNode* minRight = findMin(root->right);
            root->val = minRight->val;
            root->right = deleteNode(root->right, minRight->val);
        }

        return root;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
};

int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    // Delete a node with key = 3
    int key = 3;
    Solution solution;
    TreeNode* result = solution.deleteNode(root, key);

    // Print the in-order traversal of the resulting tree
    inOrderTraversal(result);
    cout << endl;

    // Clean up the memory by deleting the tree nodes
    deleteTree(result);

    return 0;
}

void inOrderTraversal(TreeNode* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->val << " ";
        inOrderTraversal(root->right);
    }
}

void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}
