#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialized;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        
        while (!nodeQueue.empty()) {
            TreeNode* curr = nodeQueue.front();
            nodeQueue.pop();
            
            if (curr == nullptr) {
                serialized += "null ";
            } else {
                serialized += to_string(curr->val) + " ";
                nodeQueue.push(curr->left);
                nodeQueue.push(curr->right);
            }
        }
        
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        string val;
        queue<TreeNode*> nodeQueue;
        
        iss >> val;
        if (val == "null") {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(stoi(val));
        nodeQueue.push(root);
        
        while (!nodeQueue.empty()) {
            TreeNode* curr = nodeQueue.front();
            nodeQueue.pop();
            
            iss >> val;
            if (val != "null") {
                curr->left = new TreeNode(stoi(val));
                nodeQueue.push(curr->left);
            }
            
            iss >> val;
            if (val != "null") {
                curr->right = new TreeNode(stoi(val));
                nodeQueue.push(curr->right);
            }
        }
        
        return root;
    }
};

int main() {
    // Test the solution
    Codec codec;
    
    // Example 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(5);
    
    string serialized = codec.serialize(root1);
    cout << "Serialized: " << serialized << endl;
    
    TreeNode* deserialized = codec.deserialize(serialized);
    cout << "Deserialized: ";
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(deserialized);
    while (!nodeQueue.empty()) {
        TreeNode* curr = nodeQueue.front();
        nodeQueue.pop();
        
        if (curr == nullptr) {
            cout << "null ";
        } else {
            cout << curr->val << " ";
            nodeQueue.push(curr->left);
            nodeQueue.push(curr->right);
        }
    }
    cout << endl;
    
    // Example 2
    TreeNode* root2 = nullptr;
    
    serialized = codec.serialize(root2);
    cout << "Serialized: " << serialized << endl;
    
    deserialized = codec.deserialize(serialized);
    cout << "Deserialized: ";
    if (deserialized == nullptr) {
        cout << "null";
    }
    cout << endl;
    
    return 0;
}
