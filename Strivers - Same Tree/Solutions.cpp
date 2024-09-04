// JAVA
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        // If both nodes are null, trees are the same
        if (p == null && q == null) {
            return true;
        }
        
        // If one of the nodes is null, trees are not the same
        if (p == null || q == null) {
            return false;
        }
        
        // If values of the current nodes are different, trees are not the same
        if (p.val != q.val) {
            return false;
        }
        
        // Recursively check the left and right subtrees
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }

    // public static void main(String[] args) {
    //     // Example 1
    //     TreeNode p1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    //     TreeNode q1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    //     Solution sol = new Solution();
    //     System.out.println("Are trees p1 and q1 the same? " + sol.isSameTree(p1, q1)); // Output: true

    //     // Example 2
    //     TreeNode p2 = new TreeNode(1, new TreeNode(2), null);
    //     TreeNode q2 = new TreeNode(1, null, new TreeNode(2));
    //     System.out.println("Are trees p2 and q2 the same? " + sol.isSameTree(p2, q2)); // Output: false

    //     // Example 3
    //     TreeNode p3 = new TreeNode(1, new TreeNode(2), new TreeNode(1));
    //     TreeNode q3 = new TreeNode(1, new TreeNode(1), new TreeNode(2));
    //     System.out.println("Are trees p3 and q3 the same? " + sol.isSameTree(p3, q3)); // Output: false
    // }
}





// CPP
#include<iostream>
using namespace std;
// Definition for a binary tree node
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both trees are empty, they are the same
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // If one tree is empty and the other is not, they are not the same
        if (p == nullptr || q == nullptr) {
            return false;
        }
        
        // If the values of the current nodes are different, they are not the same
        if (p->val != q->val) {
            return false;
        }
        
        // Recursively check if the left and right subtrees are the same
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    // Create the first binary tree
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(1);
    
    // Create the second binary tree
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(1);
    q->right = new TreeNode(2);
    
    // Create an instance of the Solution class
    Solution solution;
    
    // Call the isSameTree function and print the result
    bool same = solution.isSameTree(p, q);
    std::cout << "Are the two binary trees the same? " << (same ? "Yes" : "No") << std::endl;
    
    // Clean up the memory
    delete p->right;
    delete p->left;
    delete p;
    delete q->right;
    delete q->left;
    delete q;
    
    return 0;
}




