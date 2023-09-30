#include <iostream>
#include <queue>
#include <unordered_map>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        int maxWidth = 0;
        std::queue<std::pair<TreeNode*, unsigned long long>> q; // Using unsigned long long to prevent overflow
        
        q.push({root, 1}); // Pairing each node with its index
        while (!q.empty()) {
            int size = q.size();
            unsigned long long left = q.front().second; // Leftmost node's index at this level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                unsigned long long index = q.front().second;
                q.pop();
                
                if (i == size - 1) { // Rightmost node at this level
                    maxWidth = std::max(maxWidth, static_cast<int>(index - left + 1));
                }
                
                if (node->left) {
                    q.push({node->left, index * 2});
                }
                
                if (node->right) {
                    q.push({node->right, index * 2 + 1});
                }
            }
        }
        
        return maxWidth;
    }
};

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution solution;
    int maxWidth = solution.widthOfBinaryTree(root);

    std::cout << "Maximum width of the binary tree: " << maxWidth << std::endl;

    // Clean up memory (optional)
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
