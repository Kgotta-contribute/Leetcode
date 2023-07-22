
#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k)
{
    int n = a.size(); //size of the given array.
    int xr = 0;
    map<int, int> mpp; //declaring the map.
    mpp[xr]++; //setting the value of 0.
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        // prefix XOR till index i:
        xr = xr ^ a[i];

        //By formula: x = xr^k:
        int x = xr ^ k;

        // add the occurrence of xr^k
        // to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]++;
    }
    return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}


// ```
// vector<int> a = {4, 2, 2, 6, 4};
// int k = 6;
// ```

// Step 1: Generating subarrays
// -----------------------------------
// Iteration 1 (i=0):
// - Subarray: [4]
// - XOR: 4

// Iteration 2 (i=1):
// - Subarray: [2]
// - XOR: 2

// Iteration 3 (i=2):
// - Subarray: [2]
// - XOR: 2

// Iteration 4 (i=3):
// - Subarray: [6]
// - XOR: 6

// Iteration 5 (i=4):
// - Subarray: [4]
// - XOR: 4

// Iteration 6 (i=0, j=1):
// - Subarray: [4, 2]
// - XOR: 4 ^ 2 = 6
// - XOR == k, so cnt++ => cnt = 1

// Iteration 7 (i=0, j=2):
// - Subarray: [4, 2, 2]
// - XOR: 4 ^ 2 ^ 2 = 4
// - XOR != k

// Iteration 8 (i=0, j=3):
// - Subarray: [4, 2, 2, 6]
// - XOR: 4 ^ 2 ^ 2 ^ 6 = 0
// - XOR != k

// Iteration 9 (i=0, j=4):
// - Subarray: [4, 2, 2, 6, 4]
// - XOR: 4 ^ 2 ^ 2 ^ 6 ^ 4 = 4
// - XOR != k

// Iteration 10 (i=1, j=2):
// - Subarray: [2, 2]
// - XOR: 2 ^ 2 = 0
// - XOR != k

// Iteration 11 (i=1, j=3):
// - Subarray: [2, 2, 6]
// - XOR: 2 ^ 2 ^ 6 = 6
// - XOR == k, so cnt++ => cnt = 2

// Iteration 12 (i=1, j=4):
// - Subarray: [2, 2, 6, 4]
// - XOR: 2 ^ 2 ^ 6 ^ 4 = 0
// - XOR != k

// Iteration 13 (i=2, j=3):
// - Subarray: [2, 6]
// - XOR: 2 ^ 6 = 4
// - XOR != k

// Iteration 14 (i=2, j=4):
// - Subarray: [2, 6, 4]
// - XOR: 2 ^ 6 ^ 4 = 2
// - XOR != k

// Iteration 15 (i=3, j=4):
// - Subarray: [6, 4]
// - XOR: 6 ^ 4 = 2
// - XOR != k

// Step 2: Calculate XOR and Count
// ------------------------------------
// After step 2, the count `cnt` will be 2. The subarrays with XOR equal to `k` are: [4, 2] and [2, 2, 6].

