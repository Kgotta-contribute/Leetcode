#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void findUnionAndIntersection(int arr1[], int n1, int arr2[], int n2) {
    // Using unordered_set to store unique elements for Union
    unordered_set<int> unionSet;

    // Using unordered_set to store common elements for Intersection
    unordered_set<int> intersectionSet;

    // Traverse the first array and insert elements into unionSet
    for (int i = 0; i < n1; ++i) {
        unionSet.insert(arr1[i]);
    }

    // Traverse the second array
    for (int i = 0; i < n2; ++i) {
        // If the element is not present in unionSet, insert it
        if (unionSet.find(arr2[i]) == unionSet.end()) {
            unionSet.insert(arr2[i]);
        } else {
            // If the element is already present in unionSet, insert it into intersectionSet
            intersectionSet.insert(arr2[i]);
        }
    }

    // Print Union
    cout << "Union: ";
    for (int num : unionSet) {
        cout << num << " ";
    }
    cout << endl;

    // Print Intersection
    cout << "Intersection: ";
    for (int num : intersectionSet) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int arr1[] = {7, 1, 5, 2, 3, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {3, 8, 6, 20, 7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    findUnionAndIntersection(arr1, n1, arr2, n2);

    return 0;
}
