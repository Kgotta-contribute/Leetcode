#include <iostream>
#include <vector>

// Function to rearrange the array by sign
std::vector<int> rearrangeArrayBySign(const std::vector<int>& arr) {
    std::vector<int> positive, negative, result;

    // Separate positive and negative elements
    for (int i = 0; i < arr.size(); ++i) {
        int num = arr[i];
        if (num > 0) {
            positive.push_back(num);
        } else {
            negative.push_back(num);
        }
    }

    // Rearrange alternatively
    size_t pPtr = 0, nPtr = 0;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (i % 2 == 0) {
            result.push_back(positive[pPtr++]);
        } else {
            result.push_back(negative[nPtr++]);
        }
    }

    return result;
}

int main() {
    std::vector<int> arr1 = {1,2,6,-8,-6,-3,-4,10};
    std::vector<int> result1 = rearrangeArrayBySign(arr1);
    std::cout << "Output 1: ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> arr2 = {1, 2, -3, -1, -2, -3};
    std::vector<int> result2 = rearrangeArrayBySign(arr2);
    std::cout << "Output 2: ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
#include <iostream>

// Function to rearrange the array by sign
int* rearrangeArrayBySign(const int* arr, int N) {
    int* positive = new int[N];
    int* negative = new int[N];
    int* result = new int[N];

    // Separate positive and negative elements
    int pCount = 0, nCount = 0;
    for (int i = 0; i < N; ++i) {
        if (arr[i] > 0) {
            positive[pCount++] = arr[i];
        } else {
            negative[nCount++] = arr[i];
        }
    }

    // Rearrange alternatively
    int pPtr = 0, nPtr = 0;
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            result[i] = positive[pPtr++];
        } else {
            result[i] = negative[nPtr++];
        }
    }

    delete[] positive;
    delete[] negative;
    return result;
}

int main() {
    int arr1[] = {1, 2, -4, -5};
    int N1 = sizeof(arr1) / sizeof(arr1[0]);
    int* result1 = rearrangeArrayBySign(arr1, N1);
    std::cout << "Output 1: ";
    for (int i = 0; i < N1; ++i) {
        std::cout << result1[i] << " ";
    }
    std::cout << std::endl;
    delete[] result1;

    int arr2[] = {1, 2, -3, -1, -2, -3};
    int N2 = sizeof(arr2) / sizeof(arr2[0]);
    int* result2 = rearrangeArrayBySign(arr2, N2);
    std::cout << "Output 2: ";
    for (int i = 0; i < N2; ++i) {
        std::cout << result2[i] << " ";
    }
    std::cout << std::endl;
    delete[] result2;

    return 0;
}

*/
