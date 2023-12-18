#include <iostream>
#include <string>
using namespace std;

int countDistinctSubsequences(string S, string T) {
    int m = T.length();
    int n = S.length();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = 1;
            } else if (j == 0) {
                dp[i][j] = 0;
            } else {
                if (T[i - 1] != S[j - 1]) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                }
            }
        }
    }
    return dp[m][n];
}

int main() {
    string S1 = "banana";
    string T1 = "ban";
    cout << countDistinctSubsequences(S1, T1) << endl; // Output: 3

    string S2 = "geeksforgeeks";
    string T2 = "ge";
    cout << countDistinctSubsequences(S2, T2) << endl; // Output: 6
    
    string S3 = "rabbbit";
    string T3 = "rabbit";
    cout << countDistinctSubsequences(S3, T3) << endl; // Output: 3

    string S4 = "babgbag";
    string T4 = "bag";
    cout << countDistinctSubsequences(S4, T4) << endl; // Output: 5

    return 0;
}




---------------------------------------------------------------------------------------




// MODERN APPROACH

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length();
        int n = s.length();
        vector<vector<unsigned int>> dp(m + 1, vector<unsigned int>(n + 1, 0));
        
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 1;
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (t[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    string s1 = "rabbbit";
    string t1 = "rabbit";
    cout << sol.numDistinct(s1, t1) << endl; // Output: 3

    string s2 = "babgbag";
    string t2 = "bag";
    cout << sol.numDistinct(s2, t2) << endl; // Output: 5
    
    string s3 = "banana";
    string t3 = "ban";
    cout << sol.numDistinct(s3, t3) << endl; // Output: 3

    string s4 = "geeksforgeeks";
    string t4 = "ge";
    cout << sol.numDistinct(s4, t4) << endl; // Output: 6

    return 0;
}









// JAVA MODERN
import java.util.*;

class Solution {
    public int numDistinct(String s, String t) {
        int m = t.length();
        int n = s.length();
        int[][] dp = new int[m + 1][n + 1];

        for (int j = 0; j <= n; j++) {
            dp[0][j] = 1;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (t.charAt(i - 1) == s.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[m][n];
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String s1 = "rabbbit";
        String t1 = "rabbit";
        System.out.println(sol.numDistinct(s1, t1)); // Output: 3

        String s2 = "babgbag";
        String t2 = "bag";
        System.out.println(sol.numDistinct(s2, t2)); // Output: 5

        String s3 = "banana";
        String t3 = "ban";
        System.out.println(sol.numDistinct(s3, t3)); // Output: 3

        String s4 = "geeksforgeeks";
        String t4 = "ge";
        System.out.println(sol.numDistinct(s4, t4)); // Output: 6
    }
}










// JAVA EASY
public class Main {
    public static int countDistinctSubsequences(String S, String T) {
        int m = T.length();
        int n = S.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) {
                    dp[i][j] = 1;
                } else if (j == 0) {
                    dp[i][j] = 0;
                } else {
                    if (T.charAt(i - 1) != S.charAt(j - 1)) {
                        dp[i][j] = dp[i][j - 1];
                    } else {
                        dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[m][n];
    }

    public static void main(String[] args) {
        String S1 = "banana";
        String T1 = "ban";
        System.out.println(countDistinctSubsequences(S1, T1)); // Output: 3

        String S2 = "geeksforgeeks";
        String T2 = "ge";
        System.out.println(countDistinctSubsequences(S2, T2)); // Output: 6

        String S3 = "rabbbit";
        String T3 = "rabbit";
        System.out.println(countDistinctSubsequences(S3, T3)); // Output: 3

        String S4 = "babgbag";
        String T4 = "bag";
        System.out.println(countDistinctSubsequences(S4, T4)); // Output: 5
    }
}
