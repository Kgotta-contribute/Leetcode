#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;

        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneNode;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<Node*> graph1(4);
    for (int i = 0; i < 4; ++i) {
        graph1[i] = new Node(i + 1);
    }
    graph1[0]->neighbors = {graph1[1], graph1[3]};
    graph1[1]->neighbors = {graph1[0], graph1[2]};
    graph1[2]->neighbors = {graph1[1], graph1[3]};
    graph1[3]->neighbors = {graph1[0], graph1[2]};

    Node* clonedGraph1 = solution.cloneGraph(graph1[0]);

    // Clean up memory
    for (int i = 0; i < 4; ++i) {
        delete graph1[i];
    }

    return 0;
}
