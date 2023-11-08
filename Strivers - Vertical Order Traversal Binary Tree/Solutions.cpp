#include <iostream>
#include <vector>
#include <map>
#include <queue>
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> columnMap;
        queue<pair<TreeNode*, pair<int, int>>> nodeQueue;
        nodeQueue.push({root, {0, 0}});

        while (!nodeQueue.empty()) {
            auto curr = nodeQueue.front();
            nodeQueue.pop();
            TreeNode* node = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            columnMap[col][row].push_back(node->val);

            if (node->left) {
                nodeQueue.push({node->left, {row + 1, col - 1}});
            }
            if (node->right) {
                nodeQueue.push({node->right, {row + 1, col + 1}});
            }
        }

        vector<vector<int>> result;
        for (const auto& colPair : columnMap) {
            vector<int> column;
            for (const auto& rowPair : colPair.second) {
                vector<int> nodes = rowPair.second;
                sort(nodes.begin(), nodes.end());
                column.insert(column.end(), nodes.begin(), nodes.end());
            }
            result.push_back(column);
        }

        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    vector<vector<int>> verticalOrder = solution.verticalTraversal(root);

    cout << "Vertical Order Traversal:" << endl;
    for (const auto& column : verticalOrder) {
        for (const auto& node : column) {
            cout << node << " ";
        }
        cout << endl;
    }

    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
