// ON GFG

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int count = 0;
    for (int i = 0; i < n; i++) {
        //This loop iterates through the array and increments the "count" for each element less than or equal to k.
        if (arr[i] <= k) {
            count++;
        }
    }

    //This will be used to count the number of elements greater than k.
    int outOfRange = 0;
    for (int i = 0; i < count; i++) {
        //This loop iterates through the first "count" elements of the array and increments "outOfRange" for each element greater than k.
        if (arr[i] > k) {
            //represents the number of elements greater than k within the first "count" elements of the array.
            outOfRange++;
        }
    }

    return outOfRange;
    }
};
/*
// sliding window which is better:
int minSwaps(int arr[], int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) {
            count++;
        }
    }

    int out_of_range = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i] > k) {
            out_of_range++;
        }
    }

    return out_of_range;
}
*/




// java







public class Solution {
    public int minSwap(int[] arr, int n, int k) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= k) {
                count++;
            }
        }

        int outOfRange = 0;
        for (int i = 0; i < count; i++) {
            if (arr[i] > k) {
                outOfRange++;
            }
        }

        return outOfRange;
    }
}

