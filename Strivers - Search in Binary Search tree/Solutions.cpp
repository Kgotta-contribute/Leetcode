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





// JAVA
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
        left = null;
        right = null;
    }
}

class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        if (root == null || root.val == val) {
            return root;
        }
        if (val < root.val) {
            return searchBST(root.left, val);
        } else {
            return searchBST(root.right, val);
        }
    }
}

public class Main {
    // Method for preorder traversal
    public static void preorderTraversal(TreeNode root) {
        if (root != null) {
            System.out.print(root.val + " : ");
            preorderTraversal(root.left);
            preorderTraversal(root.right);
        }
    }

    public static void main(String[] args) {
        // Create the example BST: [4,2,7,1,3]
        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.right = new TreeNode(7);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);

        Solution solution = new Solution();

        // Search for val = 2
        int val1 = 2;
        TreeNode result1 = solution.searchBST(root, val1);
        System.out.print("Search result for val=" + val1 + ": ");
        preorderTraversal(result1);
        System.out.println();

        // Search for val = 5
        int val2 = 5;
        TreeNode result2 = solution.searchBST(root, val2);
        System.out.print("Search result for val=" + val2 + ": ");
        preorderTraversal(result2);
        System.out.println();
    }
}




// PYTHON
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def searchBST(self, root, val):
        if root is None or root.val == val:
            return root
        if val < root.val:
            return self.searchBST(root.left, val)
        else:
            return self.searchBST(root.right, val)

def preorder_traversal(root):
    if root:
        print(root.val, end=" : ")
        preorder_traversal(root.left)
        preorder_traversal(root.right)

def main():
    # Create the example BST: [4,2,7,1,3]
    root = TreeNode(4)
    root.left = TreeNode(2)
    root.right = TreeNode(7)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(3)

    solution = Solution()

    # Search for val = 2
    val1 = 2
    result1 = solution.searchBST(root, val1)
    print(f"Search result for val={val1}: ", end="")
    preorder_traversal(result1)
    print()

    # Search for val = 5
    val2 = 5
    result2 = solution.searchBST(root, val2)
    print(f"Search result for val={val2}: ", end="")
    preorder_traversal(result2)
    print()

if __name__ == "__main__":
    main()
