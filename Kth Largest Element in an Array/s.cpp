#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // Push the first k elements into the min heap
        for (int i = 0; i < k; ++i) {
            minHeap.push(nums[i]);
        }
        
        // For the remaining elements, if an element is larger than the top of the min heap, 
        // pop the top and push the current element into the heap
        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        
        // The top of the min heap contains the kth largest element
        return minHeap.top();
    }
};