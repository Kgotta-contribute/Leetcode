#include <iostream>
#include <vector>
#include <unordered_map>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inorderMap) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        
        int rootIndex = inorderMap[rootVal];
        int leftSubtreeSize = rootIndex - inStart;
        
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSubtreeSize, inorder, inStart, rootIndex - 1, inorderMap);
        root->right = buildTreeHelper(preorder, preStart + leftSubtreeSize + 1, preEnd, inorder, rootIndex + 1, inEnd, inorderMap);
        
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
    Solution solution;
    
    // Example 1
    vector<int> preorder1 = {3, 9, 20, 15, 7};
    vector<int> inorder1 = {9, 3, 15, 20, 7};
    
    TreeNode* root1 = solution.buildTree(preorder1, inorder1);
    cout << "Inorder Traversal of the Constructed Tree (Example 1): ";
    printInorder(root1);
    cout << endl;
    
    // Example 2
    vector<int> preorder2 = {-1};
    vector<int> inorder2 = {-1};
    
    TreeNode* root2 = solution.buildTree(preorder2, inorder2);
    cout << "Inorder Traversal of the Constructed Tree (Example 2): ";
    printInorder(root2);
    cout << endl;
    
    return 0;
}
