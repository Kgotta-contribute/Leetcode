#include<iostream>
#include<vector>
using namespace std;

int findSingleEle(vector<int>& arr, int left, int right)
{
    if(left>right)
    {
        return -1;
    }
    if(left == right)
    {
        return arr[left];
    }
    int mid = left + (right - left) / 2;

    if(mid % 2 == 0)
    {
        //If mid ele is even check if adjacent ele is same
        if(arr[mid] == arr[mid+1])
        {
            //Single ele is on right side of array
            return findSingleEle(arr, mid+2, right);
        }
        else
        {
            //single ele is on left side of array
            return findSingleEle(arr, left, mid);
        }
    }
    else
    {
        //If middle index is odd check if adjacent ele is the same
        if(arr[mid] == arr[mid -1])
        {
            //Single ele is on right side of array
            return findSingleEle(arr, mid+1, right);
        }
        else
        {
            //Single ele is on right side
            return findSingleEle(arr, left, mid-1);
        }
    }
}
int findSingleEle(vector<int>& arr)
{
    return findSingleEle(arr, 0, arr.size()-1);
}
int main()
{
    vector<int> arr1 = {1,1,2,2,3,3,4,5,5,6,6};
    cout<<"Single Ele is: "<<findSingleEle(arr1)<<endl;

    vector<int> arr2 = {1,1,3,5,5};
    cout<<"Single Ele is: "<<findSingleEle(arr2)<<endl;

    vector<int> arr3 = {1,1,3,3,5,5,6};
    cout<<"Single Ele is: "<<findSingleEle(arr3)<<endl;

    return 0;
}


/*

The method uses binary search & assuems arr is sorted in ascending order
The obseravation is : If middle index of arr is even then single ele is on right side of array,
& if middle index is off then signle ele is on left side of arr



*/

















