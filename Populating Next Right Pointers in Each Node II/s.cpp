/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        Node* levelStart = root; // Start with the root node
        
        while (levelStart) {
            Node* curr = levelStart;
            Node* dummy = new Node(0); // Dummy node for the next level's head
            Node* prev = dummy; // Pointer to track the previous node in the next level
            
            while (curr) {
                if (curr->left) {
                    prev->next = curr->left;
                    prev = prev->next;
                }
                if (curr->right) {
                    prev->next = curr->right;
                    prev = prev->next;
                }
                curr = curr->next; // Move to the next node in the current level
            }
            
            levelStart = dummy->next; // Move to the next level
            delete dummy; // Delete the dummy node
        }
        
        return root;
    }
};