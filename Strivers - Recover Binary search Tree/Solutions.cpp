#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* first = nullptr;   // First misplaced node
    TreeNode* second = nullptr;  // Second misplaced node
    TreeNode* prev = nullptr;    // Previous node during in-order traversal

    void inorderTraversal(TreeNode* root) {
        if (!root) return;

        inorderTraversal(root->left);

        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev;
            }
            second = root;
        }
        prev = root;

        inorderTraversal(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        inorderTraversal(root);

        // Swapping values of the misplaced nodes
        swap(first->val, second->val);
    }
};

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->left->right = new TreeNode(2);
    Solution().recoverTree(root1);
    // Output should be [3, 1, null, null, 2]

    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(2);
    Solution().recoverTree(root2);
    // Output should be [2, 1, 4, null, null, 3]

    return 0;
}
