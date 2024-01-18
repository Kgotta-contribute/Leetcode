//https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/
#include<bits/stdc++.h>
using namespace std;
int maxSubarraySum(int arr[], int n) 
{
    int maximum = INT_MIN; 
    for (int i = 0; i < n; i++) 
    {
        int sum = 0;
        for (int j = i; j < n; j++) 
        {
            sum += arr[j];
            maximum = max(maximum, sum); 
        }
    }
    return maximum;
}
int main()
{
    int arr[] = { -1,2,5,-5,3,4,-9,10,5,-2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}

///////////////////////////// JAVA //////////////////////////////////

class Solution {
    public static int maxSubarraySum(int arr[], int n) {
        int maximum = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                maximum = Math.max(maximum, sum);
            }
        }
        return maximum;
    }
  
    public static void main(String args[]) {
        int arr[] = { -1, 2, 5, -5, 3, 4, -9, 10, 5, -2 };
        int n = arr.length;
        int maxSum = maxSubarraySum(arr, n);
        System.out.println("The max subarray sum is : " + maxSum);
    }
}
