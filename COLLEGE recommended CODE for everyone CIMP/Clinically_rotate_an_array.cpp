#include <iostream>
using namespace std;
// Function to rotate the array clockwise by one
void rotateArrayByOne(int arr[], int size) {
    // Store the last element of the array
    int temp = arr[size - 1];

    // Shift each element to the right
    for (int i = size - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    // Place the last element at the beginning
    arr[0] = temp;
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Example 1
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    // Rotate the array by one
    rotateArrayByOne(arr1, size1);

    // Print the rotated array
    cout << "Rotated Array 1: ";
    printArray(arr1, size1);

    // Example 2
    int arr2[] = {2, 3, 4, 5, 1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // Rotate the array by one
    rotateArrayByOne(arr2, size2);

    // Print the rotated array
    cout << "Rotated Array 2: ";
    printArray(arr2, size2);

    return 0;
}
