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