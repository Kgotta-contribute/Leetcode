#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        int postIndex = postorder.size() - 1;
        return buildTreeHelper(inorder, postorder, inorderMap, 0, inorder.size() - 1, postIndex);
    }
    
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& inorderMap, int inStart, int inEnd, int& postIndex) {
        if (inStart > inEnd) {
            return nullptr;
        }
        
        int rootVal = postorder[postIndex];
        TreeNode* root = new TreeNode(rootVal);
        int inIndex = inorderMap[rootVal];
        
        postIndex--;
        
        root->right = buildTreeHelper(inorder, postorder, inorderMap, inIndex + 1, inEnd, postIndex);
        root->left = buildTreeHelper(inorder, postorder, inorderMap, inStart, inIndex - 1, postIndex);
        
        return root;
    }
};

void printInorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    
    Solution obj;
    TreeNode* root = obj.buildTree(inorder, postorder);
    
    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    
    return 0;
}
