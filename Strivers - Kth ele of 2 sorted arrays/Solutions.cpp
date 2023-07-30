#include <iostream>
#include <vector>
using namespace std;
int findKthElement(vector<int>& nums1, vector<int>& nums2, int k) 
{
    int m = nums1.size();
    int n = nums2.size();
    int i = 0, j = 0;

    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) 
        {
            if (i + j == k - 1) 
            {
                return nums1[i];
            }
            i++;
        } 
        else 
        {
            if (i + j == k - 1) 
            {
                return nums2[j];
            }
            j++;
        }
    }

    while (i < m) 
    {
        if (i + j == k - 1) 
        {
            return nums1[i];
        }
        i++;
    }

    while (j < n) 
    {
        if (i + j == k - 1) 
        {
            return nums2[j];
        }
        j++;
    }

    return -1; // If k is out of range of merged array
}

int main() 
{
    vector<int> array1 = {2, 3, 6, 7, 9};
    vector<int> array2 = {1, 4, 8, 10};
    int k = 5;

    int kthElement = findKthElement(array1, array2, k);
    cout << kthElement << endl;

    return 0;
}

/*
#include <iostream>
#include <vector>

using namespace std;

int findKthElement(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size();
    int n = nums2.size();
    int left = max(0, k - n);
    int right = min(m, k);

    while (left < right) {
        int mid1 = left + (right - left) / 2;
        int mid2 = k - mid1;

        if (nums1[mid1] < nums2[mid2 - 1]) {
            left = mid1 + 1;
        } else {
            right = mid1;
        }
    }

    int mid1 = left;
    int mid2 = k - left;

    int num1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
    int num2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;

    return max(num1, num2);
}

int main() {
    vector<int> array1 = {2, 3, 6, 7, 9};
    vector<int> array2 = {1, 4, 8, 10};
    int k = 5;

    int kthElement = findKthElement(array1, array2, k);
    cout << kthElement << endl;

    return 0;
}
*/