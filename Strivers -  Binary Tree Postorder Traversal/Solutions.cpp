
#include <vector>
#include <stack>
#include<iostream>
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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        
        stack<TreeNode*> nodeStack;
        TreeNode* current = root;
        TreeNode* lastVisited = nullptr;
        
        while (current != nullptr || !nodeStack.empty()) {
            if (current != nullptr) {
                nodeStack.push(current);
                current = current->left;
            } else {
                TreeNode* peekNode = nodeStack.top();
                
                if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                    current = peekNode->right;
                } else {
                    result.push_back(peekNode->val);
                    lastVisited = peekNode;
                    nodeStack.pop();
                }
            }
        }
        
        return result;
    }
};

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Create an instance of the Solution class
    Solution solution;

    // Perform postorder traversal
    vector<int> result = solution.postorderTraversal(root);

    // Print the result
    cout << "Postorder traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    // Clean up the memory
    // ...

    return 0;
}
