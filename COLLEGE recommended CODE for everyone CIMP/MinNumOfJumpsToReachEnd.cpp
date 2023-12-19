#include <iostream>
using namespace std;

int minJumps(int arr[], int n) {
    if (n <= 1) {
        return 0;
    }

    if (arr[0] == 0) {
        return -1;
    }

    int maxReach = arr[0];
    int steps = arr[0];
    int jumps = 1;

    for (int i = 1; i < n; i++) {
        if (i == n - 1) {
            return jumps;
        }

        maxReach = max(maxReach, i + arr[i]);
        steps--;

        if (steps == 0) {
            jumps++;

            if (i >= maxReach) {
                return -1;
            }

            steps = maxReach - i;
        }
    }

    return -1;
}

int main() {
    int arr1[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Minimum number of jumps for arr1: " << minJumps(arr1, n1) << endl;

    int arr2[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Minimum number of jumps for arr2: " << minJumps(arr2, n2) << endl;

    return 0;
}
