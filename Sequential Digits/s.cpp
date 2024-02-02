#include <vector>
#include <queue>

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        
        // Use a queue for BFS
        queue<int> q;
        
        // Adding digits from 1 to 9 to the queue
        for (int i = 1; i <= 9; ++i) {
            q.push(i);
        }
        
        // BFS traversal
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            if (curr >= low && curr <= high) {
                result.push_back(curr);
            }
            
            int lastDigit = curr % 10;
            
            // If the last digit is less than 9, add the next sequential digit
            if (lastDigit < 9) {
                q.push(curr * 10 + lastDigit + 1);
            }
        }
        
        return result;
    }
};