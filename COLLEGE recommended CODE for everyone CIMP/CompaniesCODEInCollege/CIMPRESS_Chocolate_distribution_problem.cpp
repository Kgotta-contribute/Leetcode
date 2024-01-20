#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int findMinDifference(int arr[], int n, int numStudents) {
    if (numStudents > n) {
        cout << "Number of students cannot be more than the number of chocolate packets." << endl;
        return -1;
    }

    sort(arr, arr + n);

    int minDifference = INT_MAX;

    for (int i = 0; i + numStudents - 1 < n; ++i) {
        int currentDifference = arr[i + numStudents - 1] - arr[i];
        minDifference = min(minDifference, currentDifference);
    }

    return minDifference;
}

int main() {
    // Example 1
    int arr1[] = {7, 3, 2, 4, 9, 12, 56};
    int numStudents1 = 3;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Minimum Difference is " << findMinDifference(arr1, n1, numStudents1) << endl;

    // Example 2
    int arr2[] = {3, 4, 1, 9, 56, 7, 9, 12};
    int numStudents2 = 5;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Minimum Difference is " << findMinDifference(arr2, n2, numStudents2) << endl;

    // Example 3
    int arr3[] = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    int numStudents3 = 7;
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Minimum Difference is " << findMinDifference(arr3, n3, numStudents3) << endl;

    return 0;
}



/*
Sort the array: arr1 becomes {2, 3, 4, 7, 9, 12, 56}
Iterate through the sorted array:
i=0: Chocolates {2, 3, 4}, Difference = 4 - 2 = 2
i=1: Chocolates {3, 4, 7}, Difference = 7 - 3 = 4
i=2: Chocolates {4, 7, 9}, Difference = 9 - 4 = 5
i=3: Chocolates {7, 9, 12}, Difference = 12 - 7 = 5
Minimum Difference is 2
*/





import java.util.Arrays;

public class ChocolateDistribution {

    static int findMinDifference(int[] arr, int n, int numStudents) {
        if (numStudents > n) {
            System.out.println("Number of students cannot be more than the number of chocolate packets.");
            return -1;
        }

        Arrays.sort(arr);

        int minDifference = Integer.MAX_VALUE;

        for (int i = 0; i + numStudents - 1 < n; ++i) {
            int currentDifference = arr[i + numStudents - 1] - arr[i];
            minDifference = Math.min(minDifference, currentDifference);
        }

        return minDifference;
    }

    public static void main(String[] args) {
        // Example 1
        int[] arr1 = {7, 3, 2, 4, 9, 12, 56};
        int numStudents1 = 3;
        int n1 = arr1.length;
        System.out.println("Minimum Difference is " + findMinDifference(arr1, n1, numStudents1));

        // Example 2
        int[] arr2 = {3, 4, 1, 9, 56, 7, 9, 12};
        int numStudents2 = 5;
        int n2 = arr2.length;
        System.out.println("Minimum Difference is " + findMinDifference(arr2, n2, numStudents2));

        // Example 3
        int[] arr3 = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
        int numStudents3 = 7;
        int n3 = arr3.length;
        System.out.println("Minimum Difference is " + findMinDifference(arr3, n3, numStudents3));
    }
}
