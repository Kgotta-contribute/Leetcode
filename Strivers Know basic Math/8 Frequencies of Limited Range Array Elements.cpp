#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void frequencyCount(vector<int>& arr, int N, int P) {
        // Step 1: Initialize frequency array
        vector<int> freq(N, 0);
        
        // Step 2: Count frequencies
        for (int num : arr) {
            if (num >= 1 && num <= N) {
                freq[num - 1]++;
            }
        }
        
        // Step 3: Copy the frequencies back to arr
        for (int i = 0; i < N; ++i) {
            arr[i] = freq[i];
        }

        // For elements beyond N, set them to 0 (for elements in arr but not in the range 1 to N)
        for (int i = N; i < arr.size(); ++i) {
            arr[i] = 0;
        }
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> arr1 = {2, 3, 2, 3, 5};
    int n1 = 5, p1 = 5;
    sol.frequencyCount(arr1, n1, p1);
    cout << "Output for Example 1: ";
    for (int i : arr1) {
        cout << i << " ";
    }
    cout << endl;

    // Example 2
    vector<int> arr2 = {3, 3, 3, 3};
    int n2 = 4, p2 = 3;
    sol.frequencyCount(arr2, n2, p2);
    cout << "Output for Example 2: ";
    for (int i : arr2) {
        cout << i << " ";
    }
    cout << endl;

    // Example 3
    vector<int> arr3 = {8, 9};
    int n3 = 2, p3 = 9;
    sol.frequencyCount(arr3, n3, p3);
    cout << "Output for Example 3: ";
    for (int i : arr3) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}



// OR



#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void frequencyCount(vector<int>& arr, int N, int P) {
        // Step 1: Encode frequencies in the array
        for (int i = 0; i < arr.size(); ++i) {
            int value = arr[i];
            if (value <= N) {
                // Increment the value at the correct index by (P + 1)
                arr[value - 1] += (P + 1);
            }
        }
        
        // Step 2: Update the array with actual frequencies
        for (int i = 0; i < N; ++i) {
            arr[i] = arr[i] / (P + 1);
        }

        // For elements beyond N, ensure they are set to 0 (for elements in arr but not in the range 1 to N)
        for (int i = N; i < arr.size(); ++i) {
            arr[i] = 0;
        }
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> arr1 = {2, 3, 2, 3, 5};
    int n1 = 5, p1 = 5;
    sol.frequencyCount(arr1, n1, p1);
    cout << "Output for Example 1: ";
    for (int i : arr1) {
        cout << i << " ";
    }
    cout << endl;

    // Example 2
    vector<int> arr2 = {3, 3, 3, 3};
    int n2 = 4, p2 = 3;
    sol.frequencyCount(arr2, n2, p2);
    cout << "Output for Example 2: ";
    for (int i : arr2) {
        cout << i << " ";
    }
    cout << endl;

    // Example 3
    vector<int> arr3 = {8, 9};
    int n3 = 2, p3 = 9;
    sol.frequencyCount(arr3, n3, p3);
    cout << "Output for Example 3: ";
    for (int i : arr3) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
