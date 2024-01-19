// I AM PREFERRING THIS METHOD OVER THE OTHER ONE
#include <iostream>
#include <vector>
using namespace std;

int findKRotation(const vector<int> &arr) {
    int n = arr.size();
    int low = 0, high = n - 1;
    // {4,5,6,7,0,1,2,3};
    // Perform binary search to find the rotation point
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // Check if the current mid element is greater than its next element
        if (mid < n - 1 && arr[mid] > arr[mid + 1]) {
            return mid + 1;  // Rotation point found
        }
        // Check if the left half is unsorted (contains rotation point)
        if (arr[mid] < arr[low]) {
            high = mid - 1;  // Search in the left half
        } else {
            low = mid + 1;   // Search in the right half
        }
    }
    // If the loop terminates, the array is not rotated
    return 0;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = findKRotation(arr);
    cout << "The minimum value of 'r' is: " << result << endl;

    return 0;
}




//////////////////////////////// JAVA  /////////////////////////////

import java.util.*;

class Main {
    public static int findKRotation(final List<Integer> arr) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid < n - 1 && arr.get(mid) > arr.get(mid + 1)) {
                return mid + 1;
            } 
            if (arr.get(mid) < arr.get(low)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();

        List<Integer> arr = new ArrayList<Integer>();
        System.out.print("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            arr.add(sc.nextInt());
        }

        int result = findKRotation(arr);
        System.out.println("The minimum value of 'r' is: " + result);

        sc.close();
    }
}





// OR


#include<bits/stdc++.h>
using namespace std;

int findNRotation(vector<int>& arr)
{
    int low = 0, high = arr.size() - 1, n = arr.size();
    while(low <= high)
    {
        if(arr[low] <= arr[high])   //{4,5,6,7,0,1,2,3};
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
    cout<<"The array is rotated "<<ans <<" times\n";
    return 0;
}