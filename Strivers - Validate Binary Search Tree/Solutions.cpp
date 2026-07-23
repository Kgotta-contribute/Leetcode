// QUESTION -> https://leetcode.com/problems/validate-binary-search-tree/description/

// JAVA 

class Solution {
    public boolean isValidBST(TreeNode root) {
        TreeNode[] prev = new TreeNode[1]; // prev[0] acts as our mutable box
        return inorder(root, prev);
    }
    
    private boolean inorder(TreeNode node, TreeNode[] prev) {
        if (node == null) {
            return true;
        }
        
        if (!inorder(node.left, prev)) {
            return false;
        }
        
        if (prev[0] != null && node.val <= prev[0].val) {
            return false;
        }
        prev[0] = node;
        
        return inorder(node.right, prev);
    }
}


OR 



class Solution {
    public boolean isValidBST(TreeNode root) {
        return validate(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    
    private boolean validate(TreeNode node, long low, long high) {
        if (node == null) {
            return true;
        }
        
        if (node.val <= low || node.val >= high) {
            return false;
        }
        
        return validate(node.left, low, node.val) &&
               validate(node.right, node.val, high);
    }
}





// PYTHON -> 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

 class Solution:
     def isValidBST(self, root: Optional[TreeNode]) -> bool:
         def validate(node, low, high):
             if not node:
                 return True
            
             if not (low < node.val < high):
                 return False
            
             return (validate(node.left, low, node.val) and
                     validate(node.right, node.val, high))
        
         return validate(root, float('-inf'), float('inf'))


OR 


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        prev = None
        
        def inorder(node):
            nonlocal prev
            if not node:
                return True
            
            if not inorder(node.left):
                return False
            
            if prev is not None and node.val <= prev:
                return False
            prev = node.val
            
            return inorder(node.right)
        
        return inorder(root)
        






=============================================================================================

// CPP

#include <iostream>
#include <limits>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution 
{
    bool isPossible(TreeNode* root, long long l, long long r) {
        if (root == nullptr)  return true;
        if (root->val < r and root->val > l)
            cout<<"root->left : "<<root->left<<" Left: "<<l<<" root->val "<<root->val<<" "<<"root->right : "<<root->right<<" root->val "<<root->val<<" right "<< r<< " ";
            return isPossible(root->left, l, root->val) and isPossible(root->right, root->val, r);
            //The line above is using the logical AND operator to ensure that both the left and right 
            //subtrees are valid BSTs.
            //If both recursive calls return true (i.e., both left and right subtrees are valid BSTs), 
            //then the entire expression evaluates to true, indicating that the current subtree rooted at 
            //root is also a valid BST. 
        else return false;
    }

    public:
    bool isValidBST(TreeNode* root) {
        long long int min = -1000000000000, max = 1000000000000;
        return isPossible(root, min, max);
    }
};

int main() {
    // Create the BST as given in the example
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    Solution solution1;
    bool isValid1 = solution1.isValidBST(root1);
    cout << "Example 1: " << (isValid1 ? "Valid BST" : "Not a valid BST") << endl;

    // Create another BST as given in the example
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);

    Solution solution2;
    bool isValid2 = solution2.isValidBST(root2);
    cout << "Example 2: " << (isValid2 ? "Valid BST" : "Not a valid BST") << endl;

    return 0;
}
