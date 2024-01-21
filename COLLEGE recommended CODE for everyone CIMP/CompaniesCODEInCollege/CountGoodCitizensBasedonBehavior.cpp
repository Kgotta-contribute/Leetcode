/*
You are the head of the civil authority in a locality, and your task is to determine the number of good 
citizens based on their behavior. Each citizen is represented by an array Behaviour, where Behaviour[i] 
denotes the behavior of the ith citizen. A citizen is considered good if their behavior is greater than 
the average of their neighboring citizens.

Implement a function int countGoodCitizens(int N, int* Behaviour) to find the number of good citizens in the locality.

Function Signature:
int countGoodCitizens(int N, int* Behaviour);

Input:
N: An integer representing the total number of citizens in the locality.
Behaviour: An array of size N, where Behaviour[i] represents the behavior of the ith citizen in the locality.
Output:
Return an integer representing the number of good citizens in the locality.
Constraints:
1 <= N <= 100
0 <= Behaviour[i] <= 100

Examples:

Example 1:

int N = 5;
int Behaviour[] = {1, 8, 5, 11, 7};
int result = countGoodCitizens(N, Behaviour);
Output: 3

Example 2:
int N = 6;
int Behaviour[] = {2, 1, 3, 4, 6, 5};
int result = countGoodCitizens(N, Behaviour);
Output: 4

Example 3:
int N = 5;
int Behaviour[] = {8, 6, 2, 1, 3};
int result = countGoodCitizens(N, Behaviour);
Output: 2

*/



#include <iostream>
using namespace std;

int countGoodCitizens(int N, int* Behaviour) 
{
    int goodCitizens = 0;

    // Iterate over each citizen
    for (int i = 0; i < N; ++i) {
        // Calculate the average of neighbors
        int average = 0;
        if (i > 0) {
            average += Behaviour[i - 1];
        }
        if (i < N - 1) {
            average += Behaviour[i + 1];
        }
        average /= (i > 0) + (i < N - 1);

        // Check if the current citizen is good
        if (Behaviour[i] > average) {
            goodCitizens++;
        }
    }

    return goodCitizens;
}

int main() {
    //1
    int N1 = 5;
    int Behaviour1[] = {1, 8, 5, 11, 7};
    int result1 = countGoodCitizens(N1, Behaviour1);
    cout << "Example 1 Output: " << result1 << endl;  // Output: 3

    //2
    int N2 = 6;
    int Behaviour2[] = {2, 1, 3, 4, 6, 5};
    int result2 = countGoodCitizens(N2, Behaviour2);
    cout << "Example 2 Output: " << result2 << endl;  // Output: 4

    //3
    int N3 = 5;
    int Behaviour3[] = {8, 6, 2, 1, 3};
    int result3 = countGoodCitizens(N3, Behaviour3);
    cout << "Example 3 Output: " << result3 << endl;  // Output: 2

    return 0;
}



////////////////////////////  JAVA   /////////////////////////////////



public class GoodCitizens {

    public static int countGoodCitizens(int N, int[] Behaviour) {
        int goodCitizens = 0;

        // Iterate over each citizen
        for (int i = 0; i < N; ++i) {
            // Calculate the average of neighbors
            int average = 0;
            if (i > 0) {
                average += Behaviour[i - 1];
            }
            if (i < N - 1) {
                average += Behaviour[i + 1];
            }
            average /= (i > 0) + (i < N - 1);

            // Check if the current citizen is good
            if (Behaviour[i] > average) {
                goodCitizens++;
            }
        }

        return goodCitizens;
    }

    public static void main(String[] args) {
        int N1 = 5;
        int[] Behaviour1 = {1, 8, 5, 11, 7};
        int result1 = countGoodCitizens(N1, Behaviour1);
        System.out.println("Example 1 Output: " + result1);  
    }
}



/*
For i = 0:
Behaviour[0] is 8
The average of its neighbors (Behaviour[0-1] + Behaviour[0+1]) / 2 is (0 + 6) / 2 = true                                                                       For i = 1:

For i = 1:
Behaviour[1] is 6
The average of its neighbors (Behaviour[1-1] + Behaviour[1+1]) / 2 is (8 + 2) / 2 = true


(i > 0): This condition checks if the current index i is greater than 0. If it is, the result is 1, otherwise, it's 0.

(i < N - 1): This condition checks if the current index i is less than N - 1. If it is, the result is 1, otherwise, it's 0.

The two conditions are added together, resulting in either 0, 1, or 2.

*/