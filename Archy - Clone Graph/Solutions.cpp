#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
    int value;
    vector<Node*> neighbors;
    Node() {
        value = 0;
        neighbors = vector<Node*>(); // Initialize the neighbors vector
    }
    Node(int val) {
        value = val;
        neighbors = vector<Node*>(); // Initialize the neighbors vector
    }
    Node(int val, vector<Node*> _neighbors) {
        value = val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> visited; // Used to store the mapping between original and cloned nodes

    // Function to clone a graph starting from a given node
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr; // Base case: if the input node is null, return null

        if (visited.find(node) != visited.end()) {
            return visited[node]; // If the node has already been visited, return its cloned version
        }

        Node* cloneNode = new Node(node->value); // Create a new cloned node
        visited[node] = cloneNode; // Store the mapping between the original and cloned node

        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor)); // Recursively clone the neighbors
        }

        return cloneNode; // Return the cloned node
    }
};

int main() {
    Solution solution;

    vector<Node*> graph1(4);
    for (int i = 0; i < 4; ++i) 
    {
        graph1[i] = new Node(i + 1); // Create four nodes with values 1, 2, 3, and 4
    }
    graph1[0]->neighbors = {graph1[1], graph1[3]}; // Node 1 is connected to nodes 2 and 4
    graph1[1]->neighbors = {graph1[0], graph1[2]}; // Node 2 is connected to nodes 1 and 3
    graph1[2]->neighbors = {graph1[1], graph1[3]}; // Node 3 is connected to nodes 2 and 4
    graph1[3]->neighbors = {graph1[0], graph1[2]}; // Node 4 is connected to nodes 1 and 3

    Node* clonedGraph1 = solution.cloneGraph(graph1[0]); // Clone the graph starting from node 1
    for (int i = 0; i < 4; ++i) {
        delete graph1[i]; // Clean up the original nodes
    }

    return 0;
}
