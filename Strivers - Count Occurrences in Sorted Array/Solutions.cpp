#include <iostream>
#include <vector>
//O(2LogN)
int countOccurrences(std::vector<int>& arr, int X) {
    int n = arr.size();
    int leftmostOccurrence = -1;
    int rightmostOccurrence = -1;

    // Binary search to find the leftmost occurrence of X
    int left = 0;
    int right = n - 1;
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == X) 
        {
            leftmostOccurrence = mid;
            right = mid - 1; // Continue searching to the left for the leftmost occurrence
        } 
        else if (arr[mid] > X) 
        {
            right = mid - 1;
        } 
        else 
        {
            left = mid + 1;
        }
    }
    // Binary search to find the rightmost occurrence of X
    left = 0;
    right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == X) {
            rightmostOccurrence = mid;
            left = mid + 1; // Continue searching to the right for the rightmost occurrence
        } else if (arr[mid] > X) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    // Calculate the number of occurrences
    int occurrences = rightmostOccurrence - leftmostOccurrence + 1;

    return occurrences;
}

int main() {
    std::vector<int> arr1 = {2, 2, 3, 3, 3, 3, 4};
    int X1 = 3;

    int result1 = countOccurrences(arr1, X1);
    std::cout << "Number of occurrences of " << X1 << " is: " << result1 << "\n";

    std::vector<int> arr2 = {1, 1, 2, 2, 2, 2, 2, 3};
    int X2 = 2;

    int result2 = countOccurrences(arr2, X2);
    std::cout << "Number of occurrences of " << X2 << " is: " << result2 << "\n";

    return 0;
}
