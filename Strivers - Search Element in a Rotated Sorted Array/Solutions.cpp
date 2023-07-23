#include <iostream>
#include <vector>

int searchInRotatedSortedArray(std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[left] <= arr[mid]) {
            // Left half is sorted

            if (arr[left] <= target && target < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            // Right half is sorted

            if (arr[mid] < target && target <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1; // Target not found
}

int main() {
    std::vector<int> arr1 = {4, 5, 6, 7, 0, 1, 2, 3};
    int target1 = 0;

    int result1 = searchInRotatedSortedArray(arr1, target1);
    std::cout << "Result: " << result1 << "\n";

    std::vector<int> arr2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;

    int result2 = searchInRotatedSortedArray(arr2, target2);
    std::cout << "Result: " << result2 << "\n";

    return 0;
}
