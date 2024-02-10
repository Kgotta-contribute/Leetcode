// lil compl
#include <vector>
#include <queue>
#include <cmath> // For pow function
#include <iostream>
using namespace std;

/
 * Definition for a binary tree node.
//  */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averages;
        if (root == nullptr)
            return averages;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            double levelSum = 0;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* current = q.front();
                q.pop();
                levelSum += current->val;
                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
            averages.push_back(levelSum / levelSize);
        }

        return averages;
        /*
        3
       / \
      9  20
        /  \
       15   7
        */
    }
};

// Function to print vector elements
void printVector(const vector<double>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    // Example 1
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    vector<double> result1 = sol.averageOfLevels(root1);
    printVector(result1); // Expected output: [3, 14.5, 11]
    // Example 2
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);
    root2->left->left = new TreeNode(15);
    root2->left->right = new TreeNode(7);
    vector<double> result2 = sol.averageOfLevels(root2);
    printVector(result2); // Expected output: [3, 14.5, 11]

    return 0;
}

/*
        3
       / \
      9  20
        /  \
       15   7

1. Initialization:
   We call `averageOfLevels(root)` with the root node, which is `3`.
   `averages` vector is initialized.
   Since the root node is not null, we proceed.
   We initialize a queue `q` and push the root node (`3`) into it.

2. While Loop (Iteration 1):
   `q` is not empty, so we enter the loop.
   `levelSize` is set to the size of the queue, which is 1.
   `levelSum` is initialized to 0.
   We iterate through the nodes at the current level (only the root node):
     `current` is set to the front of the queue (`3`).
     `current` is popped from the queue.
     `levelSum` is incremented by the value of `current`, which is `3`.
     Both left and right children of `current` (9 and 20) are pushed into the queue.
   The loop ends, and we calculate the average (`levelSum / levelSize`), which is `3 / 1 = 3`.
   `3` is pushed into the `averages` vector.

3. While Loop (Iteration 2):
   `q` is not empty, so we enter the loop again.
   `levelSize` is set to the size of the queue, which is 2.
   `levelSum` is reset to 0.
   We iterate through the nodes at the current level (nodes 9 and 20):
     `current` is set to the front of the queue (`9`).
     `current` is popped from the queue.
     `levelSum` is incremented by the value of `current`, which is `9`.
     No children for node `9`, so no nodes are pushed into the queue.
     Next, `current` is set to the front of the queue (`20`).
     `current` is popped from the queue.
     `levelSum` is incremented by the value of `current`, which is `20`.
     Left child of `current` (15) and right child of `current` (7) are pushed into the queue.
   The loop ends, and we calculate the average (`levelSum / levelSize`), which is `29 / 2 = 14.5`.
   `14.5` is pushed into the `averages` vector.

4. While Loop (Iteration 3):
   `q` is not empty, so we enter the loop again.
   `levelSize` is set to the size of the queue, which is 2 (nodes 15 and 7).
   `levelSum` is reset to 0.
   We iterate through the nodes at the current level (nodes 15 and 7):
     `current` is set to the front of the queue (`15`).
     `current` is popped from the queue.
     `levelSum` is incremented by the value of `current`, which is `15`.
     No children for node `15`, so no nodes are pushed into the queue.
     Next, `current` is set to the front of the queue (`7`).
     `current` is popped from the queue.
     `levelSum` is incremented by the value of `current`, which is `7`.
     No children for node `7`, so no nodes are pushed into the queue.
   The loop ends, and we calculate the average (`levelSum / levelSize`), which is `22 / 2 = 11`.
   `11` is pushed into the `averages` vector.

5. Return:
   The `averages` vector, `[3, 14.5, 11]`, is returned as the result.
*/