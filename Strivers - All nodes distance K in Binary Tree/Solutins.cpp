#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        buildParentMap(root, nullptr, parentMap);
        
        vector<int> result;
        queue<TreeNode*> nodeQueue;
        unordered_map<TreeNode*, bool> visited;
        
        nodeQueue.push(target);
        visited[target] = true;
        
        int distance = 0;
        while (!nodeQueue.empty()) {
            int size = nodeQueue.size();
            
            for (int i = 0; i < size; i++) {
                TreeNode* curr = nodeQueue.front();
                nodeQueue.pop();
                
                if (distance == k) {
                    result.push_back(curr->val);
                }
                
                if (curr->left && !visited[curr->left]) {
                    nodeQueue.push(curr->left);
                    visited[curr->left] = true;
                }
                
                if (curr->right && !visited[curr->right]) {
                    nodeQueue.push(curr->right);
                    visited[curr->right] = true;
                }
                
                TreeNode* parent = parentMap[curr];
                if (parent && !visited[parent]) {
                    nodeQueue.push(parent);
                    visited[parent] = true;
                }
            }
            
            distance++;
            if (distance > k) {
                break;
            }
        }
        
        return result;
    }
    
private:
    void buildParentMap(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if (node == nullptr) {
            return;
        }
        
        parentMap[node] = parent;
        buildParentMap(node->left, node, parentMap);
        buildParentMap(node->right, node, parentMap);
    }
};

int main() {
    Solution solution;
    
    // Example 1
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(0);
    root1->right->right = new TreeNode(8);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);
    TreeNode* target1 = root1->left;
    int k1 = 2;
    
    vector<int> result1 = solution.distanceK(root1, target1, k1);
    cout << "Output (Example 1): ";
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;
    
    // Example 2
    TreeNode* root2 = new TreeNode(1);
    TreeNode* target2 = root2;
    int k2 = 3;
    
    vector<int> result2 = solution.distanceK(root2, target2, k2);
    cout << "Output (Example 2): ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
