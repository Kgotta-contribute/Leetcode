// JAVA 

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution {
    private boolean isPossible(TreeNode root, long l, long r) {
        if (root == null) return true;
        if (root.val < r && root.val > l) {
            return isPossible(root.left, l, root.val) && isPossible(root.right, root.val, r);
        } else {
            return false;
        }
    }

    public boolean isValidBST(TreeNode root) {
        long min = -1000000000000L;
        long max = 1000000000000L;
        return isPossible(root, min, max);
    }
}

public class Main {
    public static void main(String[] args) {
        // Create the BST as given in the example
        TreeNode root1 = new TreeNode(2);
        root1.left = new TreeNode(1);
        root1.right = new TreeNode(3);

        Solution solution1 = new Solution();
        boolean isValid1 = solution1.isValidBST(root1);
        System.out.println("Example 1: " + (isValid1 ? "Valid BST" : "Not a valid BST"));

        // Create another BST as given in the example
        TreeNode root2 = new TreeNode(5);
        root2.left = new TreeNode(1);
        root2.right = new TreeNode(4);
        root2.right.left = new TreeNode(3);
        root2.right.right = new TreeNode(6);

        Solution solution2 = new Solution();
        boolean isValid2 = solution2.isValidBST(root2);
        System.out.println("Example 2: " + (isValid2 ? "Valid BST" : "Not a valid BST"));
    }
}


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
