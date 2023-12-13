#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0; // 0 coins needed to make 0 amount

        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Example 1: " << solution.coinChange(coins1, amount1) << endl; // Output: 3

    // Example 2
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Example 2: " << solution.coinChange(coins2, amount2) << endl; // Output: -1

    // Example 3
    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Example 3: " << solution.coinChange(coins3, amount3) << endl; // Output: 0

    return 0;
}







// JAVA









import java.util.Arrays;

class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0; // 0 coins needed to make 0 amount

        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != Integer.MAX_VALUE) {
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == Integer.MAX_VALUE ? -1 : dp[amount];
    }
}

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Example 1
        int[] coins1 = {1, 2, 5};
        int amount1 = 11;
        System.out.println("Example 1: " + solution.coinChange(coins1, amount1)); // Output: 3

        // Example 2
        int[] coins2 = {2};
        int amount2 = 3;
        System.out.println("Example 2: " + solution.coinChange(coins2, amount2)); // Output: -1

        // Example 3
        int[] coins3 = {1};
        int amount3 = 0;
        System.out.println("Example 3: " + solution.coinChange(coins3, amount3)); // Output: 0
    }
}




