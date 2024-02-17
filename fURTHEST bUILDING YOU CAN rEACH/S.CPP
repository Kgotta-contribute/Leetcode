#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int n = heights.size();
        
        for (int i = 0; i < n - 1; ++i) {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0) {
                pq.push(-diff);
                if (pq.size() > ladders) {
                    bricks += pq.top();
                    pq.pop();
                }
                if (bricks < 0) return i;
            }
        }
        
        return n - 1;
    }
};


int main() {
    Solution sol;
    vector<int> heights1 = {4, 2, 7, 6, 9, 14, 12};
    int bricks1 = 5, ladders1 = 1;
    cout << sol.furthestBuilding(heights1, bricks1, ladders1) << endl; // Output: 4
    
    vector<int> heights2 = {4, 12, 2, 7, 3, 18, 20, 3, 19};
    int bricks2 = 10, ladders2 = 2;
    cout << sol.furthestBuilding(heights2, bricks2, ladders2) << endl; // Output: 7
    
    vector<int> heights3 = {14, 3, 19, 3};
    int bricks3 = 17, ladders3 = 0;
    cout << sol.furthestBuilding(heights3, bricks3, ladders3) << endl; // Output: 3
    
    return 0;
}
