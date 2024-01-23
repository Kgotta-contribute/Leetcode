// take care
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        int prevValue = -1;

        inOrderTraversal(root, prevValue, minDiff);

        return minDiff;
    }

private:
    void inOrderTraversal(TreeNode* node, int& prevValue, int& minDiff) {
        if (node == nullptr) {
            return;
        }

        // Traverse the left subtree
        inOrderTraversal(node->left, prevValue, minDiff);

        // Check the difference with the previous value
        if (prevValue != -1) {
            minDiff = min(minDiff, abs(node->val - prevValue)); // Use abs for absolute difference
        }

        // Update the previous value
        prevValue = node->val;

        // Traverse the right subtree
        inOrderTraversal(node->right, prevValue, minDiff);
    }
};


// When the recursive call returns, the function checks the difference between the value of the current node and the value of the previous node. If a previous node exists, the absolute difference is calculated and compared with the current minimum difference. The minimum difference so far is updated if the new difference is smaller.

// The value of the current node is then stored as the new prevValue, and the function recursively calls itself with the right child of the current node as the new node argument.

// This process continues until all nodes in the binary search tree have been visited. The final value of minDiff is returned to the minDiffInBST function, which then returns it to the caller.