#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        if (root == nullptr) {
            return result;
        }
        
        std::queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        
        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                
                if (i == levelSize - 1) {
                    result.push_back(node->val);
                }
                
                if (node->left) {
                    nodeQueue.push(node->left);
                }
                
                if (node->right) {
                    nodeQueue.push(node->right);
                }
            }
        }
        
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution solution;
    std::vector<int> rightSide = solution.rightSideView(root);

    std::cout << "Right Side View: ";
    for (int val : rightSide) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
