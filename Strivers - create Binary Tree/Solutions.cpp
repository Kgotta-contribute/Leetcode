#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to create a binary tree from the given array
Node* createTree(vector<int>& arr) {
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);

    int i = 0;
    while (!q.empty() && i < arr.size() / 2) {
        Node* t = q.front();
        q.pop();

        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;

        if (leftIndex < arr.size()) {
            Node* left = new Node(arr[leftIndex]);
            t->left = left;
            q.push(left);
        }

        if (rightIndex < arr.size()) {
            Node* right = new Node(arr[rightIndex]);
            t->right = right;
            q.push(right);
        }

        i++;
    }

    return root;
}

// Function to print the binary tree in level order traversal
void printLevelOrder(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if (curr->left != nullptr)
                q.push(curr->left);

            if (curr->right != nullptr)
                q.push(curr->right);
        }

        cout << endl;
    }
}

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7 };

    Node* root = createTree(arr);

    cout << "Binary Tree:" << endl;
    printLevelOrder(root);

    return 0;
}
