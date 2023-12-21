#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int n, int k) {
    // Sort the array
    sort(arr, arr + n);

    // Return the K'th smallest element
    return arr[k - 1];
}

int kthLargest(int arr[], int n, int k) {
    // Sort the array in descending order
    sort(arr, arr + n, greater<int>());

    // Return the K'th largest element
    return arr[k - 1];
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k1 = 3;
    int k2 = 4;

    cout << "K'th smallest element: " << kthSmallest(arr, n, k1) << endl;
    cout << "K'th largest element: " << kthLargest(arr, n, k2) << endl;

    return 0;
}
