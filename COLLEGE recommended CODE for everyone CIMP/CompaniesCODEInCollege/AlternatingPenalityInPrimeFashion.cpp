/*
Alternating Prime Penalty

Alex has an array arr of size N and wants to construct an alternating prime sequence for a coding challenge. 
An alternating prime sequence is defined as a sequence where each prime integer is followed by a non-prime integer, 
and each non-prime integer is followed by a prime. The penalty increases by the value of the current integer if 
consecutive integers violate this pattern. Alex needs to find and print the minimum possible penalty while completing this task.

Write a program that takes the input array arr and outputs the minimum penalty.

Input Format:
The first line contains an integer, N, the size of the array.
Each of the next N lines contains a single element, representing the elements of the array arr.

Output Format:
Print the minimum possible penalty that Alex can have while completing the task.

Constraints:
1 ≤ N ≤ 104
1 ≤ arr[i] ≤ 104
Example:
Input:
6
1
3
4
6
8
10

Output:
11
Explanation:
We can create a sequence [10, 3, 8] with a penalty of 11 (6 + 4 + 1) as the minimum penalty.

Sample Input:
Copy code
2
50
2
Sample Output:
8
*/








#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;  // 0 and 1 are not prime numbers
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;  // If divisible by any number other than 1 and itself, not prime
    }
    return true;  // If not divisible by any number other than 1 and itself, prime
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int penalty = 0;
    for (int i = 0; i < N - 1; i++) {
        // Check if current and next numbers have the same primality
        if (isPrime(arr[i]) == isPrime(arr[i + 1])) {
            // If same, add the current number to penalty
            penalty += arr[i];
            // Make the current number non-prime by incrementing it
            arr[i]++;
        }
    }

    // Print the minimum possible penalty
    cout << penalty << endl;

    return 0;
}


