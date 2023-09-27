#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int kthSmallest = -1;
        TreeNode* current = root;
        
        while (current != nullptr) {
            if (current->left == nullptr) {
                count++;
                if (count == k) {
                    kthSmallest = current->val;
                }
                current = current->right;
            } else {
                TreeNode* predecessor = current->left;
                while (predecessor->right != nullptr && predecessor->right != current) {
                    predecessor = predecessor->right;
                }
                
                if (predecessor->right == nullptr) {
                    predecessor->right = current;
                    current = current->left;
                } else {
                    predecessor->right = nullptr;
                    count++;
                    if (count == k) {
                        kthSmallest = current->val;
                    }
                    current = current->right;
                }
            }
        }
        
        return kthSmallest;
    }
};

int main() {
    // Create the BST as given in the example
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root1->left->right = new TreeNode(2);

    // Find the 1st smallest element (k = 1)
    int k1 = 1;
    Solution solution1;
    int result1 = solution1.kthSmallest(root1, k1);
    cout << "Kth Smallest Element: " << result1 << endl;

    // Create another BST as given in the example
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(6);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(4);
    root2->left->left->left = new TreeNode(1);

    // Find the 3rd smallest element (k = 3)
    int k2 = 3;
    Solution solution2;
    int result2 = solution2.kthSmallest(root2, k2);
    cout << "Kth Smallest Element: " << result2 << endl;
    
    // Clean up the memory by deleting the tree nodes (not shown in the original code)
    
    return 0;
}
