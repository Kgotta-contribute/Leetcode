//https://takeuforward.org/arrays/find-out-how-many-times-the-array-has-been-rotated/

#include <bits/stdc++.h>
using namespace std;
int findRotationIndex(vector<int> &arr) // Pass by reference
{
    int size = arr.size();
    int minValue = INT_MAX;         // Infinity
    int rotationIndex = -1;         // Take care & do not forget
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] < minValue)  // 4 < 1L; 5<4
        {
            minValue = arr[i];  // 4, 
            rotationIndex = i;  // 0
        }
    }
    return rotationIndex;
}
int main() 
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int rotationCount = findRotationIndex(arr);
    cout << "The array is rotated " << rotationCount << " times.\n";
    return 0;
}





// JAVA 


import java.util.Arrays;

public class ArrayRotation {
    static int findRotationIndex(int[] arr) {
        int size = arr.length;
        int minValue = Integer.MAX_VALUE;
        int rotationIndex = -1;

        for (int i = 0; i < size; i++) {
            if (arr[i] < minValue) {
                minValue = arr[i];
                rotationIndex = i;
            }
        }

        return rotationIndex;
    }

    public static void main(String[] args) {
        int[] arr = {4, 5, 6, 7, 0, 1, 2, 3};
        int rotationCount = findRotationIndex(arr);
        System.out.println("The array is rotated " + rotationCount + " times.");
    }
}
