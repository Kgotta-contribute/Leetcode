#include <vector>
#include <unordered_map>

class Solution {
public:
    int findJudge(int n, std::vector<std::vector<int>>& trust) {
        // Create two vectors for in-degree and out-degree
        std::vector<int> inDegree(n + 1, 0);
        std::vector<int> outDegree(n + 1, 0);
        
        // Populate in-degree and out-degree vectors based on trust relationships
        for (const auto& relation : trust) {
            int a = relation[0];
            int b = relation[1];
            outDegree[a]++;
            inDegree[b]++;
        }
        
        // Check for a person who satisfies properties 1 and 2
        for (int i = 1; i <= n; ++i) {
            if (inDegree[i] == n - 1 && outDegree[i] == 0) {
                return i;
            }
        }
        
        // If no such person found, return -1
        return -1;
    }
};
