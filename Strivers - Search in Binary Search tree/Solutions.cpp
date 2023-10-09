#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if(root == nullptr || root->val == val)
        {
            return root;
        }
        if(val < root->val)
        {
            return searchBST(root->left, val);
        }
        if(val > root->val)
        {
            return searchBST(root->right, val);
        }
    }
};

void preorderTraversal(TreeNode* root) 
{
    if(root != nullptr)
    {
        cout<<root->val<<" : ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    // Create the example BST: [4,2,7,1,3]
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution solution;

    // search for val = 2
    int val1 = 2;
    TreeNode* result1 = solution.searchBST(root, val1);
    cout << "Search result for val=" << val1 << ": ";
    preorderTraversal(result1);
    cout << endl;

    // search for val = 5
    int val2 = 5;
    TreeNode* result2 = solution.searchBST(root, val2);
    cout << "Search result for val=" << val2 << ": ";
    preorderTraversal(result2);
    cout << endl;

    return 0;
}
