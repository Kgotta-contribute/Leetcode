
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
            return result;

        stack<TreeNode*> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty()) {
            TreeNode* curr = nodeStack.top();
            nodeStack.pop();

            result.insert(result.begin(), curr->val);

            if (curr->left)
                nodeStack.push(curr->left);
            if (curr->right)
                nodeStack.push(curr->right);
        }

        return result;
    }
};

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Create an instance of the Solution class
    Solution solution;

    // Get the postorder traversal of the binary tree
    vector<int> postorder = solution.postorderTraversal(root);

    // Print the result
    cout << "Postorder Traversal: ";
    for (int num : postorder) {
        cout << num << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
