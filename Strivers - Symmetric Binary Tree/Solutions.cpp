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



// JAVA
public class Main {
    static class TreeNode {
        int val;
        TreeNode left, right;

        TreeNode(int x) {
            val = x;
            left = null;
            right = null;
        }
    }

    public static boolean isSymm(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) {
            return true;
        }
        if (root1 == null || root2 == null) {
            return false;
        }
        if (root1.val != root2.val) {
            return false;
        }
        return isSymm(root1.left, root2.right) && isSymm(root1.right, root2.left);
    }

    public static boolean isSymm(TreeNode root) {
        if (root == null) {
            return true;
        }
        return isSymm(root.left, root.right);
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(2);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(4);
        root.right.left = new TreeNode(4);
        root.right.right = new TreeNode(3);

        if (isSymm(root)) {
            System.out.println("The binary tree is symmetric");
        } else {
            System.out.println("The binary tree is not symmetric");
        }

        // No explicit memory management needed in Java as garbage collection handles it.
    }
}





// PYTHON

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def isSymm(root1, root2):
    if root1 is None and root2 is None:
        return True
    if root1 is None or root2 is None:
        return False
    if root1.val != root2.val:
        return False
    return isSymm(root1.left, root2.right) and isSymm(root1.right, root2.left)

def isSymmetric(root):
    if root is None:
        return True
    return isSymm(root.left, root.right)

def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(2)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(4)
    root.right.left = TreeNode(4)
    root.right.right = TreeNode(3)

    if isSymmetric(root):
        print("The binary tree is symmetric")
    else:
        print("The binary tree is not symmetric")

if __name__ == "__main__":
    main()
