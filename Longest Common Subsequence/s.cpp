#include <iostream>
#include <vector>

class Solution {
public:
// WATCH YT
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        // Create a 2D vector to store the length of the common subsequence
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the dp vector based on the characters of text1 and text2
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    // If characters match, extend the common subsequence
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // If characters don't match, take the maximum from the previous rows
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // The result is stored in the bottom-right cell of the dp matrix
        return dp[m][n];
    }
};

int main() {
    Solution solution;
    cout << solution.longestCommonSubsequence("abcde", "ace") << endl; // Output: 3
    cout << solution.longestCommonSubsequence("abc", "abc") << endl;    // Output: 3
    cout << solution.longestCommonSubsequence("abc", "def") << endl;    // Output: 0

    return 0;
}
