// You are given the root of a binary search tree (BST) and an integer val.

// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.
         
//          4
//         / \
//        2   7
//       / \
//      1   3


// Example 1:

// Input: root = [4,2,7,1,3], val = 2
// Output: [2,1,3]
// Example 2:

// Input: root = [4,2,7,1,3], val = 5
// Output: []

#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Start from the root node.
        TreeNode* current = root;
        
        while (current) {
            if (current->val == val) {
                return current; // Found the node with the given value.
            } else if (current->val < val) {
                current = current->right; // Move to the right subtree.
            } else {
                current = current->left; // Move to the left subtree.
            }
        }
        
        return nullptr; // Node with val not found in the BST.
    }
};

// Function to print the tree (inorder traversal)
void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    // Example tree creation
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Search for values in the tree
    int val1 = 2;
    int val2 = 5;
    
    Solution solution;
    TreeNode* result1 = solution.searchBST(root, val1);
    TreeNode* result2 = solution.searchBST(root, val2);

    // Print the inorder traversal of the results
    cout << "Inorder Traversal of Result 1: ";
    inorderTraversal(result1);
    cout << endl;

    cout << "Inorder Traversal of Result 2: ";
    inorderTraversal(result2);
    cout << endl;

    return 0;
}




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
    public TreeNode searchBST(TreeNode root, int val) {
        // Start from the root node.
        TreeNode current = root;
        
        while (current != null) {
            if (current.val == val) {
                return current; // Found the node with the given value.
            } else if (current.val < val) {
                current = current.right; // Move to the right subtree.
            } else {
                current = current.left; // Move to the left subtree.
            }
        }
        
        return null; // Node with val not found in the BST.
    }
    
    public static void main(String[] args) {
        // Example tree creation
        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.right = new TreeNode(7);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);

        // Search for values in the tree
        int val1 = 2;
        int val2 = 5;
        
        Solution solution = new Solution();
        TreeNode result1 = solution.searchBST(root, val1);
        TreeNode result2 = solution.searchBST(root, val2);

        // Print the inorder traversal of the results
        System.out.print("Inorder Traversal of Result 1: ");
        inorderTraversal(result1);
        System.out.println();

        System.out.print("Inorder Traversal of Result 2: ");
        inorderTraversal(result2);
        System.out.println();
    }
    
    // Function to print the tree (inorder traversal)
    private static void inorderTraversal(TreeNode root) {
        if (root != null) {
            inorderTraversal(root.left);
            System.out.print(root.val + " ");
            inorderTraversal(root.right);
        }
    }
}





// We will search for two values: val1 = 2 and val2 = 5.

// Start from the root node, which is 4.

// Compare 4 with val1 = 2. Since 4 is greater, we move to the left subtree.
// Compare 2 with val1 = 2. We found a match, so we return the node with value 2 as the result.
// Now, we search for val2 = 5.

// Start from the root node again, which is 4.
// Compare 4 with val2 = 5. Since 4 is greater, we move to the right subtree.
// Now, we are at node 7.
// Compare 7 with val2 = 5. Since 7 is greater, we move to the left subtree of node 7, which is nullptr.
// Since there are no more nodes to explore, we return nullptr as the result because val2 = 5 is not present in the BST.