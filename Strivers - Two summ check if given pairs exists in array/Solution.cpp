#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

string twoSumExists(int arr[], int n, int target) {
    unordered_set<int> numSet;
    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        if (numSet.find(complement) != numSet.end()) {
            return "YES";
        }
        numSet.insert(arr[i]);
    }
    return "NO";
}
// arr = {2, 6, 5, 8, 11} and target = 14:

// Iteration 1: complement = 14 - 2 = 12. numSet is {2}.
// Iteration 2: complement = 14 - 6 = 8. numSet is {2, 6}.
// Iteration 3: complement = 14 - 5 = 9. numSet is {2, 6, 5}.
// Iteration 4: complement = 14 - 8 = 6. numSet already contains 6, so return "YES".
// Output: "YES"

vector<int> twoSumIndices(int arr[], int n, int target) {
    unordered_map<int, int> numIndices;
    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        if (numIndices.find(complement) != numIndices.end()) {
            return {numIndices[complement], i};
        }
        numIndices[arr[i]] = i;
    }
    return {-1, -1};
}
// For arr = {2, 6, 5, 8, 11} and target = 14:

// Iteration 1: complement = 14 - 2 = 12. numIndices is {2: 0}.
// Iteration 2: complement = 14 - 6 = 8. numIndices is {2: 0, 6: 1}.
// Iteration 3: complement = 14 - 5 = 9. numIndices is {2: 0, 6: 1, 5: 2}.
// Iteration 4: complement = 14 - 8 = 6. numIndices already contains 6 with index 1, so return {1, 3}.

// Iteration 4 (i = 3):

// arr[3] = 8. complement = 14 - 8 = 6.
// numIndices already contains 6 with index 1 (numIndices[6] = 1).
// Return: {1, 3}. This is because numIndices[6] is 1 and i is 3, indicating that elements at indices 1 and 3 (6 and 8 respectively) sum up to 14.

int main() {
    int arr[] = {2, 6, 5, 8, 11};
    int target = 14;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Variant 1: Two-Sum Exists?" << endl;
    cout << twoSumExists(arr, n, target) << endl;

    cout << "\nVariant 2: Two-Sum Indices" << endl;
    vector<int> indices = twoSumIndices(arr, n, target);
    if (indices[0] == -1 && indices[1] == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << indices[0] << " " << indices[1] << endl;
    }

    return 0;
}







// JAVA

import java.util.HashMap;
import java.util.HashSet;

public class TwoSum {

    String twoSumExists(int[] arr, int n, int target) {
        HashSet<Integer> numSet = new HashSet<>();
        for (int i = 0; i < n; i++) {
            int complement = target - arr[i];
            if (numSet.contains(complement)) {
                return "YES";
            }
            numSet.add(arr[i]);
        }
        return "NO";
    }

    int[] twoSumIndices(int[] arr, int n, int target) {
        HashMap<Integer, Integer> numIndices = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int complement = target - arr[i];
            if (numIndices.containsKey(complement)) {
                return new int[]{numIndices.get(complement), i};
            }
            numIndices.put(arr[i], i);
        }
        return new int[]{-1, -1};
    }

    public static void main(String[] args) {
        TwoSum twoSum = new TwoSum(); // Create an instance of the class
        int[] arr = {2, 6, 5, 8, 11};
        int target = 14;
        int n = arr.length;

        System.out.println("Variant 1: Two-Sum Exists?");
        System.out.println(twoSum.twoSumExists(arr, n, target));

        System.out.println("\nVariant 2: Two-Sum Indices");
        int[] indices = twoSum.twoSumIndices(arr, n, target);
        if (indices[0] == -1 && indices[1] == -1) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
            System.out.println(indices[0] + " " + indices[1]);
        }
    }
}




// PYTHON
# module for type annotations
from typing import List, Tuple

# Function to check if two numbers in the array sum up to the target
def two_sum_exists(arr: List[int], target: int) -> str:
    # Use a set to store seen numbers
    num_set = set()
    # Iterate through each number in the array
    for num in arr:
        # Calculate the complement needed to reach the target
        complement = target - num
        # Check if complement exists in the set
        if complement in num_set:
            return "YES"  # Return "YES" if complement found
        num_set.add(num)  # Add current number to set if complement not found
    return "NO"  # Return "NO" if no such pair found

# Function to find indices of two numbers that sum up to the target
def two_sum_indices(arr: List[int], target: int) -> Tuple[int, int]:
    # Use a dictionary to store numbers and their indices
    num_indices = {}
    # Iterate through each number and its index in the array
    for i, num in enumerate(arr):
        # Calculate the complement needed to reach the target
        complement = target - num
        # Check if complement exists in the dictionary
        if complement in num_indices:
            return num_indices[complement], i  # Return indices if complement found
        num_indices[num] = i  # Store current number and its index in the dictionary
    return -1, -1  # Return (-1, -1) if no such pair found

if __name__ == "__main__":
        arr = [2, 6, 5, 8, 11]
    target = 14

    print("Variant 1: Two-Sum Exists?")
    print(two_sum_exists(arr, target))  he result

    print("\nVariant 2: Two-Sum Indices")
    indices = two_sum_indices(arr, target)  he result
    if indices == (-1, -1):
        print("NO")  
    else:
        print("YES")  
        print(indices[0], indices[1])  




-------------------------------------------------
// EASY METHOD

/*
#include <bits/stdc++.h>
using namespace std;

string twoSum(int n, vector<int> &arr, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) return "YES";
        }
    }
    return "NO";
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 1: " << ans << endl;
    return 0;
}
*/