
#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;
        TreeNode* curr = root;
        
        while (curr != nullptr || !nodeStack.empty()) {
            while (curr != nullptr) {
                nodeStack.push(curr);
                curr = curr->left;
            }
            
            curr = nodeStack.top();
            nodeStack.pop();
            result.push_back(curr->val);
            
            curr = curr->right;
        }
        
        return result;
    }
};

int main() {
    // Test case 1
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    Solution solution;
    vector<int> result = solution.inorderTraversal(root);
    
    cout << "Inorder traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

