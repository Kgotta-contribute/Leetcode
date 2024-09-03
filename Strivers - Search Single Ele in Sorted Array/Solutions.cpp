// JAVA 
class Solution {
    public int singleNonDuplicate(int[] nums) {
        int left = 0;
        int right = nums.length - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Ensure mid is even to simplify comparison
            //Why Ensure mid is Even? In a sorted array where each element (except one) appears exactly twice, pairs of elements are always adjacent and start at even indices. For instance, if an element at index i is paired with an element at index i + 1, then i must be even.
            if (mid % 2 == 1) {
                mid--;  // Adjust mid to be even
            }

            // Check if the element at mid is equal to the next element
            if (nums[mid] == nums[mid + 1]) {
                // The single element is in the right half
                left = mid + 2; // Update left to mid + 2 to skip the current pair and search in the right half of the array.
            } else {
                // The single element is in the left half
                right = mid;    // This means that the element at mid is not paired with the next element. This scenario implies that the unique element is in the left half or is the current nums[mid] itself.
            }
        }

        // When left meets right, we have found the single element
        // By the end of the binary search process, left will equal right, and both pointers point to the single non-duplicate element.
        // At this point, the unique element is precisely at the left (or right) index of the array.
        // You will get same result with nums[right]
        return nums[left];
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        // Example 1
        int[] nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
        System.out.println("Single element in nums1: " + sol.singleNonDuplicate(nums1));  // Output: 2

        // Example 2
        int[] nums2 = {3, 3, 7, 7, 10, 11, 11};
        System.out.println("Single element in nums2: " + sol.singleNonDuplicate(nums2));  // Output: 10
    }
}





// CPP
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Ensure mid is even
            if (mid % 2 == 1) {
                mid--; // Adjust mid to be even
            }

            // Compare mid and mid+1
            if (nums[mid] == nums[mid + 1]) {
                // Unique element is in the right half
                left = mid + 2;
            } else {
                // Unique element is in the left half
                right = mid;
            }
        }

        // When left meets right, we have found the unique element
        return nums[left];
    }
};



//          OR

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

