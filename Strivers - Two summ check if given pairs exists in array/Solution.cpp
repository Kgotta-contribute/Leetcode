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








// numSet.find(complement): The find() function is used to search for a specific element (complement) in the numSet unordered set. If the element is found, it returns an iterator pointing to that element; otherwise, it returns an iterator pointing to the end of the set.

// numSet.endJ(): The end() function returns an iterator pointing to the end of the set. It represents a position just past the last element in the set.

// numSet.find(complement) != numSet.end(): This expression compares the iterator returned by find(complement) with the iterator returned by end(). If they are not equal, it means that the element (complement) was found in the set.


//VERSION 1

// #include <iostream>
// #include <unordered_set>
// using namespace std;

// string twoSumExists(int arr[], int n, int target) {
//     unordered_set<int> numSet;

//     for (int i = 0; i < n; i++) {
//         int complement = target - arr[i];
//         if (numSet.find(complement) != numSet.end()) {
//             return "YES";
//         }
//         numSet.insert(arr[i]);
//     }

//     return "NO";
// }

// int main() {
//     int arr[] = {2, 6, 5, 8, 11};
//     int target = 14;
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << twoSumExists(arr, n, target) << endl;

//     return 0;
// }



// VERSION 2
/*
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

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

int main() {
    int arr[] = {2, 6, 5, 8, 11};
    int target = 14;
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> indices = twoSumIndices(arr, n, target);
    if (indices[0] == -1 && indices[1] == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << indices[0] << " " << indices[1] << endl;
    }

    return 0;
}

*/




// BOTH IN ONE CODE:-

/*
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


numSet.find(complement): The find() function is used to search for a specific element (complement) in the numSet unordered set. If the element is found, it returns an iterator pointing to that element; otherwise, it returns an iterator pointing to the end of the set.

numSet.end(): The end() function returns an iterator pointing to the end of the set. It represents a position just past the last element in the set.

numSet.find(complement) != numSet.end(): This expression compares the iterator returned by find(complement) with the iterator returned by end(). If they are not equal, it means that the element (complement) was found in the set.



*/


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