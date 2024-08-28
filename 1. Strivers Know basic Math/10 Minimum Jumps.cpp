#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minJumps(int arr[], int n) {
        if (n == 0 || arr[0] == 0) {
            return -1; // No jumps possible if the first element is 0 or array is empty
        }
        
        if (n == 1) {
            return 0; // No jump needed if there's only one element
        }

        int jumps = 0; // Number of jumps made
        int current_end = 0; // End of the current jump
        int farthest = 0; // Farthest point that can be reached in the next jump
        
        for (int i = 0; i < n; ++i) {
            farthest = max(farthest, i + arr[i]);
            
            // If we have reached the end of the array, no need for more jumps
            if (i == n - 1) {
                return jumps;
            }
            
            // If we have reached the end of the range of the current jump
            if (i == current_end) {
                jumps++;
                current_end = farthest;
                
                // If the current_end is already beyond or at the last element
                if (current_end >= n - 1) {
                    return jumps;
                }
            }
        }
        
        return -1; // If not possible to reach the end
    }
};

int main() {
    Solution sol;
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = sol.minJumps(arr, n);
    cout << "Minimum number of jumps: " << result << endl;
    
    return 0;
}
