//https://takeuforward.org/data-structure/peak-element-in-array/

#include<bits/stdc++.h>
using namespace std;
int findPeak(vector<int> &arr)
{
    int size = arr.size();
    for(int i=0; i<size; i++)
    {
        if((i==0 || arr[i]>arr[i-1]) && (i==size-1 || arr[i]>arr[size-1]))
        {
            return i;
        }
    }
    return -1;
} 
int main()
{
    vector<int>arr = {1,2,3,4,5,6,7,8,6,5,1};
    int ans = findPeak(arr);
    cout<<"\nThe peak element is at index : "<<ans<<" "<<endl;
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr) {
    int n = arr.size(); //Size of array.

    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        if (arr[mid] > arr[mid - 1]) low = mid + 1;

        else high = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}
*/