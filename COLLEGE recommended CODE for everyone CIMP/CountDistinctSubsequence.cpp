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

/*
example `s1 = "rabbbit"` and `t1 = "rabbit"`:

1. **Initialization:**
   - `dp[0][j]` is initialized to 1 for all `j` (columns). This is because, for an empty string `t`, there 
   is one subsequence in any string `s` (the empty subsequence).
   - In the code, the loop `for (int j = 0; j <= n; j++)` sets `dp[0][j] = 1` for all `j`, initializing the first row.

   ```
   dp array after initialization: {{1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0}}
   ```

2. **Main Iterations:**
   - The nested loops (`for (int i = 1; i <= m; i++)` and `for (int j = 1; j <= n; j++)`) iterate over each cell in 
   the `dp` array, starting from `i=1` and `j=1`.

   - **Iteration 1 (i=1, j=1):**
     - `t[0] = 'r', s[0] = 'r'`: Characters match!
     - `dp[1][1] = dp[0][0] + dp[1][0] = 1 + 0 = 1`
     - The value in the cell `dp[1][1]` represents the number of distinct subsequences of `"r"` in `"r"`.

   - **Iteration 2 (i=1, j=2):**
     - `t[0] = 'r', s[1] = 'a'`: No match, copy from the previous cell in the same row.
     - `dp[1][2] = dp[1][1] = 1`
     - The value in the cell `dp[1][2]` represents the number of distinct subsequences of `"r"` in `"ra"`.

   - **Iteration 3 (i=1, j=3):**
     - `t[0] = 'r', s[2] = 'b'`: No match, copy from the previous cell in the same row.
     - `dp[1][3] = dp[1][2] = 1`
     - The value in the cell `dp[1][3]` represents the number of distinct subsequences of `"r"` in `"rab"`.

   - ... Continue these iterations until you complete the row.

   ```
   dp array after all iterations: {{1, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1}}
   ```

3. **Final Result:**
   - The final result is obtained from `dp[m][n]`, which represents the number of distinct subsequences of `t1` in `s1`.

   ```
   Result: dp[2][7] = 3
   ```

   - The value `3` indicates that there are 3 distinct subsequences of `"rabbit"` in `"rabbbit"`: {"ra_b_", "rab_b_", "rabb_it"}.

The values in `dp[i][j]` represent the number of distinct subsequences of the substring `t[0..i-1]` in 
the substring `s[0..j-1]`. The dynamic programming approach efficiently calculates these values based on whether the 
characters at the current positions match or not.




iterations after `i=1, j=3`:

- **Iteration 4 (i=1, j=4):**
  - `t[0] = 'r', s[3] = 'b'`: No match, copy from the previous cell in the same row.
  - `dp[1][4] = dp[1][3] = 1`
  - The value in the cell `dp[1][4]` represents the number of distinct subsequences of `"r"` in `"rabb"`.

- **Iteration 5 (i=1, j=5):**
  - `t[0] = 'r', s[4] = 'b'`: No match, copy from the previous cell in the same row.
  - `dp[1][5] = dp[1][4] = 1`
  - The value in the cell `dp[1][5]` represents the number of distinct subsequences of `"r"` in `"rabbb"`.

- **Iteration 6 (i=1, j=6):**
  - `t[0] = 'r', s[5] = 'i'`: No match, copy from the previous cell in the same row.
  - `dp[1][6] = dp[1][5] = 1`
  - The value in the cell `dp[1][6]` represents the number of distinct subsequences of `"r"` in `"rabbbi"`.

- **Iteration 7 (i=1, j=7):**
  - `t[0] = 'r', s[6] = 't'`: No match, copy from the previous cell in the same row.
  - `dp[1][7] = dp[1][6] = 1`
  - The value in the cell `dp[1][7]` represents the number of distinct subsequences of `"r"` in `"rabbbit"`.

Now, the row for `i=1` is complete:

```
dp array after iteration 7: {{1, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1}}
```

- **Iteration 8 (i=2, j=1):**
  - `t[1] = 'a', s[0] = 'r'`: No match, copy from the cell above in the same column.
  - `dp[2][1] = dp[1][1] = 1`
  - The value in the cell `dp[2][1]` represents the number of distinct subsequences of `"ra"` in `"r"`.

- **Iteration 9 (i=2, j=2):**
  - `t[1] = 'a', s[1] = 'a'`: Characters match!
  - `dp[2][2] = dp[1][1] + dp[2][1] = 1 + 1 = 2`
  - The value in the cell `dp[2][2]` represents the number of distinct subsequences of `"ra"` in `"raa"`.

- ... Continue these iterations until you complete the entire `dp` array.

The final `dp` array would look like this:

```
{{1, 0, 0, 0, 0, 0, 0},
 {0, 1, 1, 1, 1, 1, 1},
 {0, 1, 1, 2, 2, 2, 3}}
```

And the result would be obtained from `dp[m][n] = dp[2][7] = 3`, indicating that there are 3 distinct 
subsequences of `"rabbit"` in `"rabbbit"`: {"ra_b_", "rab_b_", "rabb_it"}.







- **Iteration 8 (i=2, j=3):**
  - `t[1] = 'a', s[2] = 'b'`: No match, copy from the cell above in the same column.
  - `dp[2][3] = dp[2][2] = 2`
  - The value in the cell `dp[2][3]` represents the number of distinct subsequences of `"ra"` in `"rabb"`.

- **Iteration 9 (i=2, j=4):**
  - `t[1] = 'a', s[3] = 'b'`: No match, copy from the cell above in the same column.
  - `dp[2][4] = dp[2][3] = 2`
  - The value in the cell `dp[2][4]` represents the number of distinct subsequences of `"ra"` in `"rabbb"`.

- **Iteration 10 (i=2, j=5):**
  - `t[1] = 'a', s[4] = 'b'`: No match, copy from the cell above in the same column.
  - `dp[2][5] = dp[2][4] = 2`
  - The value in the cell `dp[2][5]` represents the number of distinct subsequences of `"ra"` in `"rabbbi"`.

- **Iteration 11 (i=2, j=6):**
  - `t[1] = 'a', s[5] = 'i'`: No match, copy from the cell above in the same column.
  - `dp[2][6] = dp[2][5] = 2`
  - The value in the cell `dp[2][6]` represents the number of distinct subsequences of `"ra"` in `"rabbbit"`.

- **Iteration 12 (i=2, j=7):**
  - `t[1] = 'a', s[6] = 't'`: No match, copy from the cell above in the same column.
  - `dp[2][7] = dp[2][6] = 2`
  - The value in the cell `dp[2][7]` represents the number of distinct subsequences of `"ra"` in `"rabbbit"`.

Now, the row for `i=2` is complete:

```
dp array after iteration 12: {{1, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1}, {0, 1, 1, 2, 2, 2, 3}}
```


Certainly! Here's the final `dp` array after all iterations:

```
{{1, 0, 0, 0, 0, 0, 0},
 {0, 1, 1, 1, 1, 1, 1},
 {0, 1, 1, 2, 2, 2, 3}}
```

In this array:

- `dp[0][0]` represents the number of distinct subsequences of an empty string `""` in an empty string `""`, which is 1.

- `dp[1][j]` represents the number of distinct subsequences of `"r"` in the substring `"rabbbit"` for different values of `j`.

- `dp[2][j]` represents the number of distinct subsequences of `"ra"` in the substring `"rabbbit"` for different values of `j`.

- The result is obtained from `dp[2][7]`, which represents the number of distinct subsequences of `"rabbit"` in `"rabbbit"`. 
The value is `3`, indicating there are 3 distinct subsequences: {"ra_b_", "rab_b_", "rabb_it"}.
*/








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
