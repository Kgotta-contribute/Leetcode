#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class BSTIterator {
private:
    stack<TreeNode*> nodeStack;
    
    // Push all left children of a node onto the stack
    void pushLeftChildren(TreeNode* root) {
        while (root != nullptr) {
            nodeStack.push(root);
            root = root->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        // Initialize the stack with leftmost path from root
        pushLeftChildren(root);
    }
    
    int next() {
        // Get the top node from the stack
        TreeNode* current = nodeStack.top();
        nodeStack.pop();
        
        // If the popped node has a right subtree, push left children of the right subtree onto the stack
        if (current->right != nullptr) {
            pushLeftChildren(current->right);
        }
        
        return current->val;
    }
    
    bool hasNext() {
        // If the stack is not empty, there are more nodes to traverse
        return !nodeStack.empty();
    }
};
