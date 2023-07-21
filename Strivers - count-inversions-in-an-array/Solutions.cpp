#include <iostream>
#include <vector>

using namespace std;

int countInversionsBruteForce(vector<int>& arr) {
    int count = 0;
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i])
                count++;
        }
    }

    return count;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    cout << "Output 1: " << countInversionsBruteForce(arr1) << endl;

    vector<int> arr2 = {5, 4, 3, 2, 1};
    cout << "Output 2: " << countInversionsBruteForce(arr2) << endl;

    vector<int> arr3 = {5, 3, 2, 1, 4};
    cout << "Output 3: " << countInversionsBruteForce(arr3) << endl;

    return 0;
}













// // HARDER & BETTER
// #include <iostream>
// #include <vector>

// using namespace std;

// int count = 0;

// void merge(vector<int>& arr, int left, int mid, int right) {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     vector<int> L(n1);
//     vector<int> R(n2);

//     for (int i = 0; i < n1; i++)
//         L[i] = arr[left + i];

//     for (int i = 0; i < n2; i++)
//         R[i] = arr[mid + 1 + i];

//     int i = 0, j = 0, k = left;

//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         } else {
//             arr[k] = R[j];
//             j++;
//             count += (n1 - i); // Counting the inversions here
//         }
//         k++;
//     }

//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }

// void mergeSort(vector<int>& arr, int left, int right) {
//     if (left < right) {
//         int mid = left + (right - left) / 2;
//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid + 1, right);
//         merge(arr, left, mid, right);
//     }
// }

// int countInversions(vector<int>& arr) {
//     count = 0;
//     mergeSort(arr, 0, arr.size() - 1);
//     return count;
// }

// int main() {
//     vector<int> arr1 = {1, 2, 3, 4, 5};
//     cout << "Output 1: " << countInversions(arr1) << endl;

//     vector<int> arr2 = {5, 4, 3, 2, 1};
//     cout << "Output 2: " << countInversions(arr2) << endl;

//     vector<int> arr3 = {5, 3, 2, 1, 4};
//     cout << "Output 3: " << countInversions(arr3) << endl;

//     return 0;
// }




