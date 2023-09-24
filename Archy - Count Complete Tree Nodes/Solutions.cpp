#include <iostream>
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
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        if (leftHeight == rightHeight) {
            // The left subtree is a perfect binary tree
            return (1 << leftHeight) + countNodes(root->right);
        } else {
            // The right subtree is a perfect binary tree
            return (1 << rightHeight) + countNodes(root->left);
        }
    }
    
private:
    int getHeight(TreeNode* node) {
        int height = 0;
        while (node != nullptr) {
            height++;
            node = node->left;
        }
        return height;
    }
};

int main() {
    // Create the example tree [1,2,3,4,5,6]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    
    Solution solution;
    int nodeCount = solution.countNodes(root);
    
    std::cout << "The number of nodes in the tree is: " << nodeCount << std::endl;
    
    return 0;
}
