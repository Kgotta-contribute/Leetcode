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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        return isMirror(root->left, root->right);
    }
    
private:
    bool isMirror(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode == nullptr && rightNode == nullptr) {
            return true;
        }
        
        if (leftNode == nullptr || rightNode == nullptr || leftNode->val != rightNode->val) {
            return false;
        }
        
        return isMirror(leftNode->left, rightNode->right) && isMirror(leftNode->right, rightNode->left);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution solution;
    bool isSymmetric = solution.isSymmetric(root);

    std::cout << "Is the tree symmetric? " << (isSymmetric ? "Yes" : "No") << std::endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
