#include <iostream>

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        return isMirror(root->left, root->right);
    }
    
private:
    bool isMirror(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode == nullptr && rightNode == nullptr) {
            return true;
        }
        
        if (leftNode == nullptr || rightNode == nullptr || leftNode->val != rightNode->val) {
            return false;
        }
        
        return isMirror(leftNode->left, rightNode->right) && isMirror(leftNode->right, rightNode->left);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution solution;
    bool isSymmetric = solution.isSymmetric(root);

    std::cout << "Is the tree symmetric? " << (isSymmetric ? "Yes" : "No") << std::endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}




// JAVA


// TreeNode class definition
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    
    // Default constructor
    TreeNode() {
        this.val = 0;
        this.left = null;
        this.right = null;
    }
    
    // Constructor with value
    TreeNode(int x) {
        this.val = x;
        this.left = null;
        this.right = null;
    }
    
    // Constructor with value, left, and right children
    TreeNode(int x, TreeNode left, TreeNode right) {
        this.val = x;
        this.left = left;
        this.right = right;
    }
}

// Solution class to check if the tree is symmetric
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        
        return isMirror(root.left, root.right);
    }
    
    private boolean isMirror(TreeNode leftNode, TreeNode rightNode) {
        if (leftNode == null && rightNode == null) {
            return true;
        }
        
        if (leftNode == null || rightNode == null || leftNode.val != rightNode.val) {
            return false;
        }
        
        return isMirror(leftNode.left, rightNode.right) && isMirror(leftNode.right, rightNode.left);
    }
}

// Main class to test the solution
public class Main {
    public static void main(String[] args) {
        // Creating the tree nodes
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(2);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(4);
        root.right.left = new TreeNode(4);
        root.right.right = new TreeNode(3);

        // Creating the Solution object
        Solution solution = new Solution();
        boolean isSymmetric = solution.isSymmetric(root);

        // Printing the result
        System.out.println("Is the tree symmetric? " + (isSymmetric ? "Yes" : "No"));
    }
}











// PYTHON

class TreeNode:
    def __init__(self, x, left=None, right=None):
        self.val = x
        self.left = left
        self.right = right

class Solution:
    def isSymmetric(self, root):
        if root is None:
            return True
        return self.isMirror(root.left, root.right)
    
    def isMirror(self, leftNode, rightNode):
        if leftNode is None and rightNode is None:
            return True
        if leftNode is None or rightNode is None:
            return False
        if leftNode.val != rightNode.val:
            return False
        return self.isMirror(leftNode.left, rightNode.right) and self.isMirror(leftNode.right, rightNode.left)

def main():
    # Creating the tree nodes
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(2)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(4)
    root.right.left = TreeNode(4)
    root.right.right = TreeNode(3)

    # Creating the Solution object
    solution = Solution()
    isSymmetric = solution.isSymmetric(root)

    # Printing the result
    print("Is the tree symmetric?", "Yes" if isSymmetric else "No")

if __name__ == "__main__":
    main()
