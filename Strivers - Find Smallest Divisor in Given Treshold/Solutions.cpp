#include<bits/stdc++.h>
using namespace std;

int sumByD(vector<int>& arr, int div)
{
    int n = arr.size();
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}
int smallestDivisor(vector<int>& arr, int limit)
{
    int n = arr.size();
    if(n>limit)
        return -1;
    int low = 1, high = *max_element(arr.begin(), arr.end());

    while(low <= high)
    {
        int mid = (low+high)/2;
        if(sumByD(arr, mid) <= limit)
        {
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}
int main()
{
    vector<int> arr = {1,2,3,4,5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout<<"The min divisor is: "<<ans<<"\n";
    return 0;
}