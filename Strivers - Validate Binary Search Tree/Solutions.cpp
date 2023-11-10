// #include <iostream>
// #include <limits>
// using namespace std;

// // struct TreeNode {
// //     int val;
// //     TreeNode* left;
// //     TreeNode* right;
// //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// // };

// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         return isValidBST(root, nullptr, nullptr);
//     }

// private:
//     bool isValidBST(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
//         if (node == nullptr) {
//             return true;
//         }

//         if ((minNode != nullptr && node->val <= minNode->val) || (maxNode != nullptr && node->val >= maxNode->val)) {
//             return false;
//         }

//         return isValidBST(node->left, minNode, node) && isValidBST(node->right, node, maxNode);
//     }
// };

// // int main() {
// //     // Example 1: Valid BST
// //     TreeNode* root1 = new TreeNode(2);
// //     root1->left = new TreeNode(1);
// //     root1->right = new TreeNode(3);

// //     Solution solution1;
// //     bool isValid1 = solution1.isValidBST(root1);
// //     cout << "Example 1: " << (isValid1 ? "Valid BST" : "Not a valid BST") << endl;

// //     // Example 2: Invalid BST
// //     TreeNode* root2 = new TreeNode(5);
// //     root2->left = new TreeNode(1);
// //     root2->right = new TreeNode(4);
// //     root2->right->left = new TreeNode(3);
// //     root2->right->right = new TreeNode(6);

// //     Solution solution2;
// //     bool isValid2 = solution2.isValidBST(root2);
// //     cout << "Example 2: " << (isValid2 ? "Valid BST" : "Not a valid BST") << endl;

// //     // Clean up the memory by deleting the tree nodes (not shown in the original code)

// //     return 0;
// // }

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

class Solution {
private:
    bool isPossible(TreeNode* root, long long l, long long r) {
        if (root == nullptr)  return true;
        if (root->val < r and root->val > l)
            return isPossible(root->left, l, root->val) and isPossible(root->right, root->val, r);
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
