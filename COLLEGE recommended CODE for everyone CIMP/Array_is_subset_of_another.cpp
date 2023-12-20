#include <iostream>
#include <unordered_set>
#include<bits/stdc++.h>
using namespace std;

bool isSubset(int arr1[], int m, int arr2[], int n) {
    // Create a set to store elements of arr1
    unordered_set<int> set;

    // Insert all elements of arr1 into the set
    for (int i = 0; i < m; ++i) {
        set.insert(arr1[i]);
    }

    // Check if all elements of arr2 are present in the set
    for (int i = 0; i < n; ++i) {
        if (set.find(arr2[i]) == set.end()) {
            // If any element of arr2 is not found in arr1, it is not a subset
            return false;
        }
    }
    // All elements of arr2 are found in arr1, so it is a subset
    return true;
}

int main() {
    // Example 1
    int arr1_1[] = {11, 1, 13, 21, 3, 7};
    int arr2_1[] = {11, 3, 7, 1};
    int m1 = sizeof(arr1_1) / sizeof(arr1_1[0]);
    int n1 = sizeof(arr2_1) / sizeof(arr2_1[0]);
    if (isSubset(arr1_1, m1, arr2_1, n1)) {
        cout << "arr2[] is a subset of arr1[]" << endl;
    } else {
        cout << "arr2[] is not a subset of arr1[]" << endl;
    }

    // Example 2
    int arr1_2[] = {1, 2, 3, 4, 5, 6};
    int arr2_2[] = {1, 2, 4};
    int m2 = sizeof(arr1_2) / sizeof(arr1_2[0]);
    int n2 = sizeof(arr2_2) / sizeof(arr2_2[0]);
    if (isSubset(arr1_2, m2, arr2_2, n2)) {
        cout << "arr2[] is a subset of arr1[]" << endl;
    } else {
        cout << "arr2[] is not a subset of arr1[]" << endl;
    }

    // Example 3
    int arr1_3[] = {10, 5, 2, 23, 19};
    int arr2_3[] = {19, 5, 3};
    int m3 = sizeof(arr1_3) / sizeof(arr1_3[0]);
    int n3 = sizeof(arr2_3) / sizeof(arr2_3[0]);
    if (isSubset(arr1_3, m3, arr2_3, n3)) {
        cout << "arr2[] is a subset of arr1[]" << endl;
    } else {
        cout << "arr2[] is not a subset of arr1[]" << endl;
    }

    return 0;
}
