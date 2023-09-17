#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;
        
        if (root == nullptr)
            return result;
        
        nodeStack.push(root);
        
        while (!nodeStack.empty()) {
            TreeNode* currNode = nodeStack.top();
            nodeStack.pop();
            
            result.push_back(currNode->val);
            
            if (currNode->right != nullptr)
                nodeStack.push(currNode->right);
            
            if (currNode->left != nullptr)
                nodeStack.push(currNode->left);
        }
        
        return result;
    }
};

int main() {
    // Create the binary tree [1, null, 2, 3]
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    Solution solution;
    vector<int> preorder = solution.preorderTraversal(root);
    
    // Print the preorder traversal
    cout << "Preorder traversal: ";
    for (int num : preorder) {
        cout << num << " ";
    }
    cout << endl;
    
    // Clean up memory
    delete root->right->left;
    delete root->right;
    delete root;
    
    return 0;
}
