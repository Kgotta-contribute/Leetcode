#include <iostream>
#include <unordered_set>
using namespace std;

bool isSubset(int arr1[], int m, int arr2[], int n) {
    unordered_set<int> hashset;

    for (int i = 0; i < m; i++) {
        hashset.insert(arr1[i]);
    }

    for (int i = 0; i < n; i++) {
        /* This line checks if the element arr2[i] is present in the hashset.
hashset.find(arr2[i]): This line returns an iterator to the first occurrence of the element arr2[i] in the hashset.
hashset.end(): This is the end iterator of the hashset, used to indicate that the element is not present in the hashset.*/
        if (hashset.find(arr2[i]) == hashset.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {11, 3, 7, 1};
    int n = sizeof(arr2) / sizeof(arr2[0]);

    if (isSubset(arr1, m, arr2, n)) {
        cout << "arr2[] is a subset of arr1[]" << endl;
    } else {
        cout << "arr2[] is not a subset of arr1[]" << endl;
    }

    int arr3[] = {1, 2, 3, 4, 5, 6};
    m = sizeof(arr3) / sizeof(arr3[0]);
    int arr4[] = {1, 2, 4};
    n = sizeof(arr4) / sizeof(arr4[0]);

    if (isSubset(arr3, m, arr4, n)) {
        cout << "arr4[] is a subset of arr3[]" << endl;
    } else {
        cout << "arr4[] is not a subset of arr3[]" << endl;
    }

    int arr5[] = {10, 5, 2, 23, 19};
    m = sizeof(arr5) / sizeof(arr5[0]);
    int arr6[] = {19, 5, 3};
    n = sizeof(arr6) / sizeof(arr6[0]);

    if (isSubset(arr5, m, arr6, n)) {
        cout << "arr6[] is a subset of arr5[]" << endl;
    } else {
        cout << "arr6[] is not a subset of arr5[]" << endl;
    }

    return 0;
}





// JAVA



import java.util.HashSet;

public class Main {
    public static boolean isSubset(int[] arr1, int m, int[] arr2, int n) {
        HashSet<Integer> hashset = new HashSet<>();

        for (int i = 0; i < m; i++) {
            hashset.add(arr1[i]);
        }

        for (int i = 0; i < n; i++) {
            if (!hashset.contains(arr2[i])) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {

        int[] arr3 = {1, 2, 3, 4, 5, 6};
        m = arr3.length;
        int[] arr4 = {1, 2, 4};
        n = arr4.length;

        if (isSubset(arr3, m, arr4, n)) {
            System.out.println("arr4[] is a subset of arr3[]");
        } else {
            System.out.println("arr4[] is not a subset of arr3[]");
        }
    }
}
