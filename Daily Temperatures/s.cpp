#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0); // Initialize the result array with 0s
        stack<int> st; // Use a stack to store the indices of temperatures
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                result[prevIndex] = i - prevIndex; // Calculate the number of days to wait
            }
            st.push(i); // Push the current index to the stack
        }
        
        return result;
    }
};

/*
temperatures = [73, 74, 75, 71, 69, 72, 76, 73].

n = 8.
result vector is initialized with 8 elements, all set to 0.
An empty stack st is created to store indices.

For Loop:
I1 (i = 0):
temperatures[0] is 73. Stack is empty, so push index 0 onto the stack.
I2 (i = 1):
temperatures[1] is 74. Since 74 is greater than 73, pop the index 0 from the stack and set 
result[0] = 1 (i - prevIndex).
Push index 1 onto the stack.
I3 (i = 2):
temperatures[2] is 75. Since 75 is greater than 74, pop the index 1 from the stack and set result[1] = 1.
Stack is now empty, so push index 2 onto the stack.
I4 (i = 3):
temperatures[3] is 71. Stack is empty, so push index 3 onto the stack.
I5 (i = 4):
temperatures[4] is 69. Stack is empty, so push index 4 onto the stack.
I6 (i = 5):
temperatures[5] is 72. Since 72 is greater than 69, pop the index 4 from the stack and set result[4] = 1.
Stack now contains [3, 5]. Push index 5 onto the stack.
I7 (i = 6):
temperatures[6] is 76. Since 76 is greater than 72, pop the index 5 from the stack and set result[5] = 1.
Stack now contains [3, 6]. Pop the index 6 from the stack and set result[6] = 1.
Stack is now [3]. Pop the index 3 from the stack and set result[3] = 3.
Stack is now empty, so push index 6 onto the stack.
I8 (i = 7):
temperatures[7] is 73. Since 73 is not greater than 76, do nothing.
Stack is not empty, so pop the index 6 from the stack and set result[6] = 0.
Result:

The final result vector is [1, 1, 4, 2, 1, 1, 0, 0]
*/