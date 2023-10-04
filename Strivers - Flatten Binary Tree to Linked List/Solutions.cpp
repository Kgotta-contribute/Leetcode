#include <iostream>
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
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        
        flatten(root->left);
        flatten(root->right);
        
        //We then set the right pointer of the root to the flattened left subtree and set the left pointer to nullptr. This effectively removes the left subtree from the root and makes it a right child.
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = nullptr;
        
        //Next, we need to find the rightmost node in the flattened left subtree. We start from the root and traverse the right child pointers until we reach the rightmost node.
//Once we find the rightmost node (curr), we set its right pointer to the original right subtree (temp). This effectively merges the flattened left subtree with the original right subtree.
        TreeNode* curr = root;
        while (curr->right != nullptr) {
            curr = curr->right;
        }
        
        curr->right = temp;
    }
};

int main() {
    // Test the solution
    Solution solution;
    
    // Example 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->right = new TreeNode(6);
    
    solution.flatten(root1);
    TreeNode* curr = root1;
    while (curr != nullptr) {
        std::cout << curr->val << " ";
        curr = curr->right;
    }
    std::cout << std::endl;
    
    // Example 2
    TreeNode* root2 = nullptr;
    
    solution.flatten(root2);
    curr = root2;
    while (curr != nullptr) {
        std::cout << curr->val << " ";
        curr = curr->right;
    }
    std::cout << std::endl;
    
    // Example 3
    TreeNode* root3 = new TreeNode(0);
    
    solution.flatten(root3);
    curr = root3;
    while (curr != nullptr) {
        std::cout << curr->val << " ";
        curr = curr->right;
    }
    std::cout << std::endl;
    
    return 0;
}
