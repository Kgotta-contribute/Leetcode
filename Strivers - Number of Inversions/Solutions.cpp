#include <iostream>
#include <vector>
using namespace std;

int numberOfInversions(vector<int>& a, int n) {
    vector<int> b = a;  // Create a copy of the original array
    int ans = 0;  // Initialize a variable to count inversions
    sort(b.begin(), b.end());  // Sort the copy of the array in non-decreasing order

    for (int i = 0; i < a.size(); i++) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);  // Find the position of the current element in the sorted array
        int x = it - b.begin();  // Calculate the number of elements smaller than the current element
        ans += x;  // Increment the inversion count by x
        b.erase(it);  // Remove the element from the sorted array to avoid counting duplicates
    }

    return ans;  // Return the total number of inversions
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int inversions = numberOfInversions(a, n);

    cout << "Number of inversions: " << inversions << endl;

    return 0;
}
