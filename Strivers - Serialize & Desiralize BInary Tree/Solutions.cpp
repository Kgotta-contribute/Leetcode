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

// The serialize function takes a TreeNode* as input and returns a string representation of the binary tree.
// It initializes an empty string serialized to store the serialized tree, and a queue nodeQueue to perform level-order traversal of the tree.
// The function performs a level-order traversal of the tree using the queue.
// For each node, it checks if the node is nullptr. If so, it appends "null" to the serialized string. Otherwise, it appends the node's value followed by a space.
// It then pushes the left and right child nodes of the current node into the nodeQueue.
// Finally, it returns the serialized string.


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


// The deserialize function takes a string data as input and returns the deserialized binary tree.
// It initializes an istringstream object iss with the data string, a string val to store the current value being read, and a queue nodeQueue to reconstruct the tree.
// It reads the first value from iss into val. If the value is "null", it means the tree is empty, so it returns nullptr.
// Otherwise, it creates a new TreeNode with the value converted from val and sets it as the root of the tree.
// It pushes the root into the nodeQueue.
// The function then enters a loop that continues until the nodeQueue is empty.
// In each iteration, it pops the front node from the nodeQueue and assigns it to curr.
// It reads the next value from iss into val. If the value is not "null", it creates a new TreeNode with the value converted from val and sets it as the left child of curr. It then pushes the left child into the nodeQueue.
// It reads the next value from iss into val. If the value is not "null", it creates a new TreeNode with the value converted from val and sets it as the right child of curr. It then pushes the right child into the nodeQueue.
// Finally, it returns the root of the deserialized tree.

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


