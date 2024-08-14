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
        //If mid ele is even check if adjacent ele is same          {1,1,2,2,3,3,4,5,5,6,6}
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



// JAVA 
public class SingleElementFinder {

    public static int findSingleElement(int[] arr, int left, int right) {
        if (left > right) {
            return -1;
        }
        if (left == right) {
            return arr[left];
        }

        int mid = left + (right - left) / 2;

        if (mid % 2 == 0) {
            // If mid index is even, check if the adjacent element is the same
            if (arr[mid] == arr[mid + 1]) {
                // Single element is on the right side of the array
                return findSingleElement(arr, mid + 2, right);
            } else {
                // Single element is on the left side of the array
                return findSingleElement(arr, left, mid);
            }
        } else {
            // If mid index is odd, check if the adjacent element is the same
            if (arr[mid] == arr[mid - 1]) {
                // Single element is on the right side of the array
                return findSingleElement(arr, mid + 1, right);
            } else {
                // Single element is on the left side of the array
                return findSingleElement(arr, left, mid - 1);
            }
        }
    }

    public static int findSingleElement(int[] arr) {
        return findSingleElement(arr, 0, arr.length - 1);
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
        System.out.println("Single Element is: " + findSingleElement(arr1));

        int[] arr2 = {1, 1, 3, 5, 5};
        System.out.println("Single Element is: " + findSingleElement(arr2));

        int[] arr3 = {1, 1, 3, 3, 5, 5, 6};
        System.out.println("Single Element is: " + findSingleElement(arr3));
    }
}




// PYTHON
def find_single_element(arr, left, right):
    if left > right:
        return -1
    if left == right:
        return arr[left]

    mid = left + (right - left) // 2

    if mid % 2 == 0:
        # If mid index is even, check if the adjacent element is the same
        if arr[mid] == arr[mid + 1]:
            # Single element is on the right side of the array
            return find_single_element(arr, mid + 2, right)
        else:
            # Single element is on the left side of the array
            return find_single_element(arr, left, mid)
    else:
        # If mid index is odd, check if the adjacent element is the same
        if arr[mid] == arr[mid - 1]:
            # Single element is on the right side of the array
            return find_single_element(arr, mid + 1, right)
        else:
            # Single element is on the left side of the array
            return find_single_element(arr, left, mid - 1)

def find_single_element_wrapper(arr):
    return find_single_element(arr, 0, len(arr) - 1)

def main():
    arr1 = [1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6]
    print("Single Element is:", find_single_element_wrapper(arr1))

    arr2 = [1, 1, 3, 5, 5]
    print("Single Element is:", find_single_element_wrapper(arr2))

    arr3 = [1, 1, 3, 3, 5, 5, 6]
    print("Single Element is:", find_single_element_wrapper(arr3))

if __name__ == "__main__":
    main()

