#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

// Function to check if the given maximum sum is feasible or not
bool isFeasible(vector<int>& nums, int k, int mid) 
{
    int count = 1;
    int sum = 0;
    for (int num : nums) 
    {
        sum += num;
        if (sum > mid) 
        {
            count++;
            sum = num;
        }
    }
    return count <= k;
}

// Function to find the minimized largest sum of the split
int splitArrayLargestSum(vector<int>& nums, int k) 
{
    int left = *max_element(nums.begin(), nums.end());
    int right = accumulate(nums.begin(), nums.end(), 0);

    while (left < right) 
    {
        int mid = left + (right - left) / 2;
        if (isFeasible(nums, k, mid)) 
        {
            right = mid;
        } 
        else 
        {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int N, k;
    cin >> N >> k;
    vector<int> a(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> a[i];
    }

    int result = splitArrayLargestSum(a, k);
    cout << "Result: " << result << endl;
    return 0;
}
