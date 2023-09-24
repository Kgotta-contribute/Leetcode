#include <iostream>
#include <vector>
#include <queue>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        
        std::queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        
        while (!q.empty()) {
            int size = q.size();
            std::vector<int> level;
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (leftToRight) {
                    level.push_back(node->val);
                } else {
                    level.insert(level.begin(), node->val);
                }
                
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            result.push_back(level);
            leftToRight = !leftToRight;
        }
        
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    std::vector<std::vector<int>> result = solution.zigzagLevelOrder(root);

    std::cout << "Zigzag Level Order Traversal: " << std::endl;
    for (const auto& level : result) {
        for (const auto& value : level) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
