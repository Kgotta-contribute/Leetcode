#include <iostream>
#include <algorithm>
using namespace std;

void rotateArray(int arr[], int n, int k, bool isRight) {
    if (k == 0) return; // No rotation required

    if (isRight) {
        reverse(arr, arr + n); // Reverse the entire array
        reverse(arr, arr + k); // Reverse the first K elements
        reverse(arr + k, arr + n); // Reverse the remaining N-K elements

    // SOMETIMES YOU GOTTA SOLVE LIKE BELOW
        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin()+k);
        // reverse(nums.begin()+k, nums.end());
    } else {
        reverse(arr, arr + n); // Reverse the entire array
        reverse(arr, arr + n - k); // Reverse the last N-K elements
        reverse(arr + n - k, arr + n); // Reverse the first K elements
// SOMETIMES YOU GOTTA SOLVE LIKE BELOW
    //     //reverses entire array
    // reverse(arr.begin(), arr.end());
    // //reverse last n-k elements
    // reverse(arr.begin(), arr.end()-1);
    // //reverse first k elements
    // reverse(arr.end()-1, arr.end());
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int N, k;
    bool isRight;
    cout << "Enter the size of the array: ";
    cin >> N;

    int array[N];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }

    cout << "Enter the value of K shifts: ";
    cin >> k;

    cout << "Enter the rotation direction (0 for left, 1 for right): ";
    cin >> isRight;

    rotateArray(array, N, k, isRight);

    cout << "Rotated Array: ";
    printArray(array, N);

    return 0;
}

