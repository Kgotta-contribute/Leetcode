#include <iostream>
using namespace std;

struct MinMax {
    int min;
    int max;
};
// The below function has a type of structure
MinMax findMinMax(int arr[], int start, int end) {
    MinMax result;
    int mid;
    MinMax left, right;

    // If there is only one element in the array
    if (start == end) {
        result.min = arr[start];
        result.max = arr[start];
        return result;
    }

    // If there are two elements in the array
    if (end == start + 1) {
        result.min = min(arr[start], arr[end]);
        result.max = max(arr[start], arr[end]);
        return result;
    }

    // If there are more than two elements, divide the array and recursively find min and max
    mid = (start + end) / 2;
    left = findMinMax(arr, start, mid);
    right = findMinMax(arr, mid + 1, end);

    // Compare the results of two recursive calls to get the overall min and max
    result.min = min(left.min, right.min);
    result.max = max(left.max, right.max);

    return result;
}

int main() {
    int arr1[] = {3, 5, 4, 1, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    MinMax result1 = findMinMax(arr1, 0, n1 - 1);
    cout << "For the first example:\n";
    cout << "Minimum element is: " << result1.min << endl;
    cout << "Maximum element is: " << result1.max << endl;

    int arr2[] = {22, 14, 8, 17, 35, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    MinMax result2 = findMinMax(arr2, 0, n2 - 1);
    cout << "\nFor the second example:\n";
    cout << "Minimum element is: " << result2.min << endl;
    cout << "Maximum element is: " << result2.max << endl;

    return 0;
}






// JAVA

class MinMax {
    int min;
    int max;
}

public class MinMaxFinder {

    static MinMax findMinMax(int[] arr, int start, int end) {
        MinMax result = new MinMax();
        int mid;
        MinMax left, right;

        // If there is only one element in the array
        if (start == end) {
            result.min = arr[start];
            result.max = arr[start];
            return result;
        }

        // If there are two elements in the array
        if (end == start + 1) {
            result.min = Math.min(arr[start], arr[end]);
            result.max = Math.max(arr[start], arr[end]);
            return result;
        }

        // If there are more than two elements, divide the array and recursively find min and max
        mid = (start + end) / 2;
        left = findMinMax(arr, start, mid);
        right = findMinMax(arr, mid + 1, end);

        // Compare the results of two recursive calls to get the overall min and max
        result.min = Math.min(left.min, right.min);
        result.max = Math.max(left.max, right.max);

        return result;
    }

    public static void main(String[] args) {
        int[] arr1 = {3, 5, 4, 1, 9};
        int n1 = arr1.length;
        MinMax result1 = findMinMax(arr1, 0, n1 - 1);
        System.out.println("For the first example:");
        System.out.println("Minimum element is: " + result1.min);
        System.out.println("Maximum element is: " + result1.max);

        int[] arr2 = {22, 14, 8, 17, 35, 3};
        int n2 = arr2.length;
        MinMax result2 = findMinMax(arr2, 0, n2 - 1);
        System.out.println("\nFor the second example:");
        System.out.println("Minimum element is: " + result2.min);
        System.out.println("Maximum element is: " + result2.max);
    }
}
