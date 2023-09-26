#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegrees(numCourses, 0);

        // Create an adjacency list and calculate in-degrees
        for (const vector<int>& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prereq = prerequisite[1];
            adjList[prereq].push_back(course);
            inDegrees[course]++;
        }

        // Initialize a queue for courses with no prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegrees[i] == 0) {
                q.push(i);
            }
        }

        int coursesTaken = 0;

        // Perform topological sorting
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            coursesTaken++;

            for (int neighbor : adjList[course]) {
                if (--inDegrees[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return coursesTaken == numCourses;
    }
};

int main() {
    Solution solution;

    // Example 1
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "Example 1: " << (solution.canFinish(numCourses1, prerequisites1) ? "true" : "false") << endl; // Output: true

    // Example 2
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << "Example 2: " << (solution.canFinish(numCourses2, prerequisites2) ? "true" : "false") << endl; // Output: false

    return 0;
}
