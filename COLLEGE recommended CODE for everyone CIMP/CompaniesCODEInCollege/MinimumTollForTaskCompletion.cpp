/*
Minimum Toll for Task Completion

Abby needs to visit certain cities to complete her pending tasks. Each task corresponds to a specific city, and Abby must 
pay a toll to travel between cities. The toll amount is determined by the absolute difference between the IDs of the two 
cities. Abby can start her journey from any city without incurring a toll.
Write a function int findMinToll(int N, int A[]) to find the minimum toll Abby must pay to complete all her tasks. The function 
takes the following parameters:

N: An integer representing the number of cities and pending tasks.
A: An array of integers where A[i] denotes the ID of the city Abby must visit to complete the ith task.
Function Signature:

int findMinToll(int N, int A[]);
Input:
N: An integer representing the number of cities and pending tasks.
A: An array of integers where A[i] (0 <= A[i] <= 1000) denotes the ID of the city Abby must visit to complete the ith task.
Output:
Return an integer representing the minimum toll Abby must pay to complete all her tasks.

Examples:
Example 1:
int N = 5;
int A[] = {1, 8, 5, 11, 7};
int result = findMinToll(N, A);
// Output: 10
Example 2:
int N = 6;
int A[] = {2, 1, 3, 4, 6, 5};
int result = findMinToll(N, A);
// Output: 6
Example 3:
int N = 5;
int A[] = {8, 6, 2, 1, 3};
int result = findMinToll(N, A);
// Output: 8
Note:
Abby can start her journey from any city and doesn't have to pay any toll to visit the first city.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int findMinToll(int N, int A[]) {
    sort(A, A + N);  // Sort the array of cities

    int minToll = 0;

    // Calculate toll based on absolute differences
    for (int i = 1; i < N; ++i) {
        minToll += abs(A[i] - A[i - 1]);
    }

    return minToll;
}

int main() {

    int N1 = 5;
    int A1[] = {1, 8, 5, 11, 7};
    int result1 = findMinToll(N1, A1);
    cout << "Example 1: " << result1 << endl;  

    int N2 = 6;
    int A2[] = {2, 1, 3, 4, 6, 5};
    int result2 = findMinToll(N2, A2);
    cout << "Example 2: " << result2 << endl;  

    int N3 = 5;
    int A3[] = {8, 6, 2, 1, 3};
    int result3 = findMinToll(N3, A3);
    cout << "Example 3: " << result3 << endl;  

    return 0;
}
/*
Sort the array A2: {1, 2, 3, 4, 5, 6}.
Calculate the toll based on absolute differences: |2-1| + |3-2| + |4-3| + |5-4| + |6-5| = 1 + 1 + 1 + 1 + 1 = 5.
*/


//////////////////////////////////   JAVA     ///////////////////////////////////////




import java.util.Arrays;

public class MinToll {
    public static int findMinToll(int N, int[] A) {

        int minToll = 0;

        for (int i = 1; i < N; i++) {
            minToll += Math.abs(A[i] - A[i - 1]);
        }
        return minToll;
    }

    public static void main(String[] args) {
        //1
        int N1 = 5;
        int[] A1 = {1, 8, 5, 11, 7};
        int result1 = findMinToll(N1, A1);
        System.out.println("Example 1: " + result1);  
    }
}