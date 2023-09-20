#include<iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left, * right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};
bool isSymm(TreeNode* root1, TreeNode* root2)
{
    if(root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    if(root1 == nullptr || root2 == nullptr)
    {
        return false;
    }
    if(root1->val != root2->val)
    {
        return false;
    }
    return isSymm(root1->left, root2->right) && isSymm(root1->right, root2->left);
}
bool isSymm(TreeNode* root)
{
    if(root == nullptr)
    {
        return true;
    }
    return isSymm(root->left, root->right);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if(isSymm(root))
    {
        cout<<"The binary tree is symm"<<endl;
    }
    else
    {
        cout<<"The binary tree is not symmetric"<<endl;
    }
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}