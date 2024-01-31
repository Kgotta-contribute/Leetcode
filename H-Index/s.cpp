#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        // Sort the citations array in descending order
        sort(citations.begin(), citations.end(), greater<int>());
        int hIndex = 0;
        // Iterate through the sorted array and find the maximum hIndex
        for (int i = 0; i < citations.size(); ++i) {
            if (citations[i] >= i + 1) {
                hIndex = i + 1;
            } else {
                break;
            }
        }
        return hIndex;
    }
};
int main() {
    Solution solution;
    vector<int> citations1 = {3, 0, 6, 1, 5};
    int result1 = solution.hIndex(citations1);
    cout << "Tcase 1: " << result1 << endl; // Output: 3
    vector<int> citations2 = {1, 3, 1};
    int result2 = solution.hIndex(citations2);
    cout << "Tcase 2: " << result2 << endl; // Output: 1
    return 0;
}
