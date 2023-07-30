#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

// Function to check if it's possible to paint all boards with 'k' painters
bool isPossible(vector<int>& boards, int k, int mid) {
    int painters = 1;
    int current_sum = 0;
    for (int board : boards) {
        current_sum += board;
        if (current_sum > mid) {
            painters++;
            current_sum = board;
        }
    }
    return painters <= k;
}

// Function to find the minimum time needed to paint all boards
int minTimeToPaintBoards(vector<int>& boards, int k) {
    int left = *max_element(boards.begin(), boards.end());
    int right = accumulate(boards.begin(), boards.end(), 0);

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isPossible(boards, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int N, k;
    cin >> N >> k;
    vector<int> boards(N);
    for (int i = 0; i < N; i++) {
        cin >> boards[i];
    }

    int result = minTimeToPaintBoards(boards, k);
    cout << "Result: " << result << endl;
    return 0;
}