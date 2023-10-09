#include <iostream>
#include <unordered_set>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return hasPairWithSum(root, k, seen);
    }
    
    bool hasPairWithSum(TreeNode* root, int k, unordered_set<int>& seen) {
        if (root == nullptr) {
            return false;
        }
        // Checking if compliment is present in seen
        if (seen.count(k - root->val)) {
            return true;
        }
        
        seen.insert(root->val);
        
        return hasPairWithSum(root->left, k, seen) || hasPairWithSum(root->right, k, seen);
    }
};

int main() {
    // Create the binary search tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int k1 = 9;
    int k2 = 28;

    Solution solution;
    bool result1 = solution.findTarget(root, k1);
    bool result2 = solution.findTarget(root, k2);

    cout << "Output for k = 9: " << (result1 ? "true" : "false") << endl;
    cout << "Output for k = 28: " << (result2 ? "true" : "false") << endl;

    return 0;
}






// #include <iostream>
// #include <stack>
// #include <unordered_set>
// using namespace std;

// /**
//  * Definition for a binary tree node.
//  */
// // struct TreeNode {
// //     int val;
// //     TreeNode* left;
// //     TreeNode* right;
// //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// //     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
// // };

// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) {
//         unordered_set<int> seen;
//         stack<TreeNode*> s;
        
//         while (root || !s.empty()) {
//             while (root) {
//                 // Check if the complement of the current node's value is in the set
//                 if (seen.count(k - root->val)) {
//                     return true;
//                 }
//                 seen.insert(root->val);
//                 s.push(root);
//                 root = root->left;
//             }
            
//             root = s.top();
//             s.pop();
//             root = root->right;
//         }
        
//         return false;
//     }
// };

// // int main() {
// //     // Create the binary search tree
// //     TreeNode* root = new TreeNode(5);
// //     root->left = new TreeNode(3);
// //     root->right = new TreeNode(6);
// //     root->left->left = new TreeNode(2);
// //     root->left->right = new TreeNode(4);
// //     root->right->right = new TreeNode(7);

// //     int k1 = 9;
// //     int k2 = 28;

// //     Solution solution;
// //     bool result1 = solution.findTarget(root, k1);
// //     bool result2 = solution.findTarget(root, k2);

// //     cout << "Output for k = 9: " << (result1 ? "true" : "false") << endl;
// //     cout << "Output for k = 28: " << (result2 ? "true" : "false") << endl;

// //     return 0;
// // }
