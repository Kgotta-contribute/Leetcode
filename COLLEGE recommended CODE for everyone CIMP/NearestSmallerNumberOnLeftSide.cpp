#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nearestSmallerOnLeft(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize result with -1
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        // Pop elements from the stack while they are greater than or equal to the current element
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        // If stack is not empty, the nearest smaller element is at the top of the stack
        if (!st.empty()) {
            result[i] = arr[st.top()];
        }

        // Push the current element's index onto the stack
        st.push(i);
    }
    return result;
}

int main() {
    vector<int> arr1 = {1, 6, 4, 10, 2, 5};
    vector<int> result1 = nearestSmallerOnLeft(arr1);

    cout << "Output for Example 1: ";
    for (int num : result1) {
        if (num == -1) {
            cout << "_ ";
        } else {
            cout << num << " ";
        }
    }
    cout << endl;

    vector<int> arr2 = {1, 3, 0, 2, 5};
    vector<int> result2 = nearestSmallerOnLeft(arr2);

    cout << "Output for Example 2: ";
    for (int num : result2) {
        if (num == -1) {
            cout << "_ ";
        } else {
            cout << num << " ";
        }
    }
    cout << endl;

    return 0;
}
