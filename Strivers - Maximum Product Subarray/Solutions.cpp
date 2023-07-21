#include<bits/stdc++.h>
using namespace std;

int maxProductSubArr(vector<int>& nums)
{
    int n = nums.size();
    if(n==0)
        return 0;

    int maxProd = nums[0];
    int minProd = nums[0];
    int res = nums[0];

    for(int i=1; i<n ; i++)
    {
        if(nums[i] < 0)
            swap(maxProd, minProd);
        maxProd = max(nums[i], maxProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);

        res = max(res, maxProd);
    }
    return res;
}
int main()
{
    vector<int> nums1 = {1,2,3,4,5,0};
    vector<int> nums2 = {1,2,-3,0,-4,-5};
    cout<<"\nOutput 1: "<<maxProductSubArr(nums1)<<endl;
    cout<<"\nOutput 2: "<<maxProductSubArr(nums2)<<endl;
    return 0;
}

/*
My num arr = {1,2,-3,0,-4,-5}

1. i=1, nums[i] = 2
    maxProd = max(2, 1*2) = 2
    minProd = min(2, 1*2) = 2
    res = max(1,2) = 2
2. i=2 nums[i] = -3
    maxProd = max(-3, 2*3) = -3
    minProd = min(-3, 2*3) = -6
    res = max(2,-3) = 2
3. i=3 nums[i] = 0                      -> we simply resest here it to 0
    maxProd = max(0, -3*0) = 0
    minProd = min(0, -6*0) = 0
    res = max(2,0) = 2
4. i=4 nums[i] = -4
    maxProd = max(-4, 0*-4) = -4
    minProd = min(-4, 0*-4) = 0
    res = max(2,-4) = 2
5. i=5 nums[i] = -5
    maxProd = max(-5, -4*-5) = 20
    minProd = min(-5, 0*-5) = -5
    res = max(2,20) = 20

*/



// EASY APPROACH

// #include<bits/stdc++.h>
// using namespace std;

// int maxProductSubArr(vector<int>& nums)
// {
//     int result = INT_MIN;
//     for(int i=0; i<nums.size()-1 ; i++)
//     {
//         for(int j=i+1; j<nums.size(); j++)
//         {
//             int prod = 1;
//             for(int k=i; k<=j; k++)
//                 prod *= nums[k];
//             result = max(result, prod);
//         }
//     }
//     return result;
// }
// int main()
// {
//     vector<int> nums = {1,2,-3,0,-4,-5};
//     cout<<"\nThe max product subarray is : "<<maxProductSubArr(nums)<<endl;
//     return 0;
// }