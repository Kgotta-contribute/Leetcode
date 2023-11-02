#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0); // 0: uncolored, 1: color 1, -1: color -1
        
        for (int i = 0; i < n; i++) {
            if (colors[i] == 0) {
                if (!bfs(graph, colors, i)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool bfs(vector<vector<int>>& graph, vector<int>& colors, int start) {
        queue<int> q;
        q.push(start);
        colors[start] = 1;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : graph[node]) {
                if (colors[neighbor] == colors[node]) {
                    return false;
                }
                
                if (colors[neighbor] == 0) {
                    colors[neighbor] = -colors[node];
                    q.push(neighbor);
                }
            }
        }
        
        return true;
    }
};

int main() {
    vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    
    Solution solution;
    bool isBipartite = solution.isBipartite(graph);
    
    cout << "Is the graph bipartite? " << (isBipartite ? "Yes" : "No") << endl;
    
    return 0;
}
