#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Create a map to store the next greater element for each number in nums2.
        unordered_map<int, int> nextGreater;
        // Create a stack to keep track of elements in nums2.
        stack<int> st;

        // Iterate through each element in nums2.
        for (int num : nums2) {
            // While the stack is not empty and the top element is less than the current element,
            // update the map with the next greater element and pop the stack.
            while (!st.empty() && st.top() < num) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            // Push the current element onto the stack.
            st.push(num);
        }

        // Create a vector to store the results.
        vector<int> result;

        // Iterate through each element in nums1.
        for (int num : nums1) {
            // If the number exists in the map, use the mapped value (next greater element),
            // otherwise, use -1 as there is no next greater element.
            result.push_back(nextGreater.count(num) ? nextGreater[num] : -1);
        }

        // Return the final result vector.
        return result;
    }
};
