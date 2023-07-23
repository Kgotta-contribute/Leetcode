#include <iostream>
#include <vector>

bool searchInRotatedSortedArrayII(std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return true;
        }

        if (arr[left] == arr[mid] && arr[mid] == arr[right]) {
            // Handle duplicates at both ends
            left++;
            right--;
        } else if (arr[left] <= arr[mid]) {
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

    return false; // Target not found
}

int main() {
    std::vector<int> arr1 = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int target1 = 3;

    bool result1 = searchInRotatedSortedArrayII(arr1, target1);
    std::cout << "Result: " << std::boolalpha << result1 << "\n";

    std::vector<int> arr2 = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int target2 = 10;

    bool result2 = searchInRotatedSortedArrayII(arr2, target2);
    std::cout << "Result: " << std::boolalpha << result2 << "\n";

    return 0;
}
