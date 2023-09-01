#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, int k) 
{
    int n = a.size();   //n=3

    int len = 0;
    for (int i = 0; i < n; i++) 
    { 
        int s = 0;
        for (int j = i; j < n; j++)     //j=0
        { 
            s += a[j];

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}int main()
{
    vector<int> a = { -1, 1, 1};
    int k = 1;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}





/*
Example:
Input array a = {-1, 1, 1} and target value k = 1.

int n = a.size();

Here, n will be assigned the value 3 since the size of array a is 3.
int len = 0;

len is initialized to 0.
First iteration of the outer loop:

i = 0
Starting index: 0
First iteration of the inner loop:

j = 0
Ending index: 0
Subarray: {-1}
Sum: -1
Since the sum -1 is not equal to the target value 1, nothing happens.
Second iteration of the inner loop:

j = 1
Ending index: 1
Subarray: {-1, 1}
Sum: 0
Since the sum 0 is not equal to the target value 1, nothing happens.
Third iteration of the inner loop:

j = 2
Ending index: 2
Subarray: {-1, 1, 1}
Sum: 1
Since the sum 1 is equal to the target value 1, the length of the current subarray (j - i + 1) is 3, which is greater than the current maximum length 0. Therefore, len is updated to 3.
Second iteration of the outer loop:

i = 1
Starting index: 1
First iteration of the inner loop:

j = 1
Ending index: 1
Subarray: {1}
Sum: 1
Since the sum 1 is equal to the target value 1, the length of the current subarray (j - i + 1) is 1, but it is not greater than the current maximum length 3. Therefore, len remains 3.
Second iteration of the inner loop:

j = 2
Ending index: 2
Subarray: {1, 1}
Sum: 2
Since the sum 2 is not equal to the target value 1, nothing happens.
Third iteration of the outer loop:

i = 2
Starting index: 2
First iteration of the inner loop:

j = 2
Ending index: 2
Subarray: {1}
Sum: 1
Since the sum 1 is equal to the target value 1, the length of the current subarray (j - i + 1) is 1, but it is not greater than the current maximum length 3. Therefore, len remains 3.
All iterations are complete. The function getLongestSubarray returns len = 3.

The main function prints: "The length of the longest subarray is: 3".
*/




// can also be done using the below approach:


// #include <bits/stdc++.h>
// using namespace std;

// int getLongestSubarray(vector<int>& nums, int k) {
//     int n = nums.size();
//     unordered_map<int, int> prefixSum; // Map to store prefix sum
//     int maxLength = 0;
//     int currentSum = 0;

//     for (int i = 0; i < n; i++) {
//         currentSum += nums[i];

//         // If currentSum is equal to k, the entire subarray from the beginning up to the current index is a valid subarray.
//         if (currentSum == k) {
//             maxLength = i + 1;
//         }

//         // If (currentSum - k) is present in prefixSum, it means there is a subarray that sums up to k.
//         if (prefixSum.find(currentSum - k) != prefixSum.end()) {
//             maxLength = max(maxLength, i - prefixSum[currentSum - k]);
//         }

//         // Store the current prefix sum and its index in the map.
//         if (prefixSum.find(currentSum) == prefixSum.end()) {
//             prefixSum[currentSum] = i;
//         }
//     }

//     return maxLength;
// }

// int main() {
//     int t;
//     cin >> t;

//     while (t--) {
//         int n, k;
//         cin >> n >> k;
//         vector<int> nums(n);

//         for (int i = 0; i < n; i++) {
//             cin >> nums[i];
//         }

//         int result = getLongestSubarray(nums, k);
//         cout << result << endl;
//     }

//     return 0;
// }
// Certainly! Here's a step-by-step explanation of how the code you provided progresses with numeric iterations:

// Let's consider a sample input and follow the code's execution:

// Sample Input:
// ```
// 2
// 3 5
// 2 3 5
// 3 1
// -1 1 1
// ```

// 1. **First Test Case (3 5, 2 3 5):**

//    - `n = 3`, the size of the input array.
//    - `maxLength = 0`, initially set to 0.
//    - `currentSum = 0`, initially set to 0.
//    - `prefixSum` is an unordered map to store prefix sums.

//    Iteration 1 (i = 0):
//      - `currentSum += nums[0]` -> `currentSum = 2`.
//      - Since `currentSum` is not equal to `k` (5), no changes to `maxLength`.
//      - `prefixSum` remains empty.
   
//    Iteration 2 (i = 1):
//      - `currentSum += nums[1]` -> `currentSum = 5`.
//      - `currentSum` is now equal to `k`, so `maxLength` is updated to `i + 1`, which is 2.
//      - `prefixSum` remains empty.

//    Iteration 3 (i = 2):
//      - `currentSum += nums[2]` -> `currentSum = 10`.
//      - Since `currentSum` is not equal to `k` (5), no changes to `maxLength`.
//      - `prefixSum` remains empty.

//    So, the result for this test case is 2.

// 2. **Second Test Case (3 1, -1 1 1):**

//    - `n = 3`, the size of the input array.
//    - `maxLength = 0`, initially set to 0.
//    - `currentSum = 0`, initially set to 0.
//    - `prefixSum` is an unordered map to store prefix sums.

//    Iteration 1 (i = 0):
//      - `currentSum += nums[0]` -> `currentSum = -1`.
//      - Since `currentSum` is not equal to `k` (1), no changes to `maxLength`.
//      - `prefixSum` remains empty.
   
//    Iteration 2 (i = 1):
//      - `currentSum += nums[1]` -> `currentSum = 0`.
//      - Since `currentSum` is not equal to `k` (1), no changes to `maxLength`.
//      - `prefixSum` remains empty.

//    Iteration 3 (i = 2):
//      - `currentSum += nums[2]` -> `currentSum = 1`.
//      - `currentSum` is now equal to `k`, so `maxLength` is updated to `i + 1`, which is 3.
//      - `prefixSum` remains empty.

//    So, the result for this test case is 3.

// The code repeats these steps for each test case in the while loop. It computes the length of the longest subarray whose sum is equal to `k` for each test case and prints the result.