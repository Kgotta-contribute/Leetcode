// could not understand properly

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






/*
for (int i = 1; i <= 9; ++i) {
    q.push(i);
}
The queue initially contains: 1, 2, 3, 4, 5, 6, 7, 8, 9.

BFS traversal:

while (!q.empty()) {
    int curr = q.front();
    q.pop();
Start the BFS traversal. In the first iteration, curr is set to the front of the queue (1) and then removed from the queue.

Checking if curr is in the range:

    if (curr >= low && curr <= high) {
        result.push_back(curr);
    }
Since 1 is between 100 and 300, it gets added to the result vector.

Finding the last digit:

    int lastDigit = curr % 10;
lastDigit is now 1 because 1 % 10 = 1.

Adding next sequential digit to the queue:

    if (lastDigit < 9) {
        q.push(curr * 10 + lastDigit + 1);
    }
Since lastDigit is less than 9, q.push(curr * 10 + lastDigit + 1) is executed. This adds 11 to the queue.

Next iteration:
The queue now contains: 2, 3, 4, 5, 6, 7, 8, 9, 11. The process repeats for the next front of the queue.

Result after a few iterations:
The result vector will contain [123, 234] as these are the sequential digits within the range.
*/