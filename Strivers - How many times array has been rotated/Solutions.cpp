#include<bits/stdc++.h>
using namespace std;

int findNRotation(vector<int>& arr)
{
    int low = 0, high = arr.size() - 1, n = arr.size();
    while(low <= high)
    {
        if(arr[low] <= arr[high])
        {
            return low;
        }
        int mid = (low + high)/2;
        //calculates the index of next ele after mid
        int next = (mid + 1) % n;

        //If ele at mid is smaller than both its previos & next ele then its min
        if(arr[mid] <= arr[(mid-1+n)%n] && arr[mid] <= arr[next])
        {
            return mid;
        }
        //If right part is sorted search in left unsorted part
        if(arr[mid] <= arr[high])
        {
            high = mid - 1;
        }
        //if left part is sorted then search right unsorted
        else
        {
            low = mid+1;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {4,5,6,7,0,1,2,3};
    int ans = findNRotation(arr);
    cout<<"The arrat is rotated "<<ans <<" times\n";
    return 0;
}


/*

OR


#include<bits/stdc++.h>
using namespace std;

int findNRotation(vector<int>& arr)
{
    int low = 0, high = arr.size()-1, ans = INT_MAX;
    int index = -1;
    while(low<=high)
    {
        int mid = (low+high)/2;

        if(arr[low] <= arr[high])
        {
            if(arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            break;
        }
        //if left part is sorted
        if(arr[low] <= arr[mid])
        {
            if(arr[low] < ans)
            {
                idex = low;
                ans = arr[low];
            }
            //eliminate left half
            low = mid + 1;
        }
        else
        {
            //if right part is sorted
            //keep min
            if(arr[mid] < ans)
            {
                index = mid;
                ans == arr[mid];
            }
            //eliminate right half
            high = mid - 1;
        }
    }
    return index;
}
int main()
{
    vector<int> arr = {4,5,6,7,0,1,2,3};
    int ans = findNRotation(arr);
    cout<<"The arrat is rotated "<<ans <<" times\n";
    return 0;
}

*/