#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int total = m + n;
    int i = 0, j = 0;
    vector<int> merged;

    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            merged.push_back(nums1[i]);
            i++;
        } else {
            merged.push_back(nums2[j]);
            j++;
        }
    }

    while (i < m) {
        merged.push_back(nums1[i]);
        i++;
    }

    while (j < n) {
        merged.push_back(nums2[j]);
        j++;
    }

    if (total % 2 == 0) 
    {
        int mid1 = merged[total / 2 - 1];
        int mid2 = merged[total / 2];
        return (double)(mid1 + mid2) / 2.0;
    } 
    else 
    {
        return (double)merged[total / 2];
    }
}

int main() {
    vector<int> arr1 = {1, 4, 7, 10, 12};
    vector<int> arr2 = {2, 3, 6, 15};

    double median = findMedianSortedArrays(arr1, arr2);
    cout << median << endl;

    return 0;
}