#include <iostream>
#include <vector>

using namespace std;

// Merge two sorted vectors
vector<int> mergeTwoSortedVectors(const vector<int>& v1, const vector<int>& v2) {
    vector<int> result;
    int i = 0, j = 0;
    
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            result.push_back(v1[i]);
            i++;
        } else {
            result.push_back(v2[j]);
            j++;
        }
    }

    // Append the remaining elements from both vectors
    while (i < v1.size()) {
        result.push_back(v1[i]);
        i++;
    }

    while (j < v2.size()) {
        result.push_back(v2[j]);
        j++;
    }

    return result;
}

// Merge k sorted arrays efficiently
vector<int> mergeKSortedArraysEfficiently(vector<vector<int>>& arrays, int left, int right) {
    if (left == right) {
        return arrays[left];
    }

    int mid = left + (right - left) / 2;
    vector<int> leftPart = mergeKSortedArraysEfficiently(arrays, left, mid);
    vector<int> rightPart = mergeKSortedArraysEfficiently(arrays, mid + 1, right);

    return mergeTwoSortedVectors(leftPart, rightPart);
}

int main() {
    // Example 1
    int k1 = 3, n1 = 4;
    vector<vector<int>> arr1 = {{1, 3, 5, 7}, {2, 4, 6, 8}, {0, 9, 10, 11}};
    vector<int> result1 = mergeKSortedArraysEfficiently(arr1, 0, k1 - 1);

    cout << "Output for Example 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Example 2
    int k2 = 4, n2 = 4;
    vector<vector<int>> arr2 = {{1, 5, 6, 8}, {2, 4, 10, 12}, {3, 7, 9, 11}, {13, 14, 15, 16}};
    vector<int> result2 = mergeKSortedArraysEfficiently(arr2, 0, k2 - 1);

    cout << "Output for Example 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}






/*
EG:
// Initial call
mergeKSortedArraysEfficiently(arr2, 0, 3)
  |
  |--- mergeKSortedArraysEfficiently(arr2, 0, 1)
  |       |
  |       |--- mergeTwoSortedVectors({1, 5, 6, 8}, {2, 4, 10, 12}) -> {1, 2, 4, 5, 6, 8, 10, 12}
  |
  |--- mergeKSortedArraysEfficiently(arr2, 2, 3)
          |
          |--- mergeTwoSortedVectors({3, 7, 9, 11}, {13, 14, 15, 16}) -> {3, 7, 9, 11, 13, 14, 15, 16}

// Final result
mergeTwoSortedVectors({1, 2, 4, 5, 6, 8, 10, 12}, {3, 7, 9, 11, 13, 14, 15, 16}) -> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}

*/
