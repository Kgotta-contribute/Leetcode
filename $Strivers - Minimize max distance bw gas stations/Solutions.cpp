#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

// Function to check if it's possible to add 'k' new gas stations with 'dist' as the maximum distance
bool isPossible(vector<int>& arr, int k, double dist) {
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        double gap = arr[i + 1] - arr[i];
        count += ceil(gap / dist) - 1;
    }
    return count <= k;
}

// Function to find the minimum value of 'dist'
double minimizeMaxDistance(vector<int>& arr, int k) {
    double left = 0;
    double right = arr[arr.size() - 1] - arr[0];

    while (right - left > 1e-6) {
        double mid = left + (right - left) / 2.0;
        if (isPossible(arr, k, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return left;
}

int main() {
    int N, k;
    cin >> N >> k;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    double result = minimizeMaxDistance(arr, k);
    cout.precision(6);
    cout << "Result: " << fixed << result << endl;
    return 0;
}