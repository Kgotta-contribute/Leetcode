#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX; // Initialize the minimum price to a large value.
        int maxProfit = 0;     // Initialize the maximum profit to 0.

        for (int price : prices) {
            // Update the minimum price if the current price is smaller.
            minPrice = min(minPrice, price);

            // Calculate the potential profit if we sell at the current price.
            int potentialProfit = price - minPrice;

            // Update the maximum profit if the potential profit is greater.
            maxProfit = max(maxProfit, potentialProfit);
        }

        return maxProfit;
    }
};

int main() {
    // Example 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    Solution solution1;
    int profit1 = solution1.maxProfit(prices1);
    cout << "Example 1 Output: " << profit1 << endl;

    // Example 2
    vector<int> prices2 = {7, 6, 4, 3, 1};
    Solution solution2;
    int profit2 = solution2.maxProfit(prices2);
    cout << "Example 2 Output: " << profit2 << endl;

    return 0;
}



// Example 1:

// Input: std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
// The maxProfit function is called with prices1.
// minPrice is initialized to a very large value, and maxProfit is initialized to 0.
// The for loop iterates through each element in prices1.
// For the first element, 7, it updates minPrice to 7 and calculates potentialProfit as 0.
// For the second element, 1, it updates minPrice to 1 and calculates potentialProfit as -6.
// For the third element, 5, it updates minPrice to 1 and calculates potentialProfit as 4.
// For the fourth element, 3, it updates minPrice to 1 and calculates potentialProfit as 2.
// For the fifth element, 6, it updates minPrice to 1 and calculates potentialProfit as 5.
// For the sixth element, 4, it updates minPrice to 1 and calculates potentialProfit as 3.
// The maximum profit among all potential profits is 5.
// The function returns 5, which is printed as "Example 1 Output: 5."
// Example 2:

// Input: std::vector<int> prices2 = {7, 6, 4, 3, 1};
// The maxProfit function is called with prices2.
// minPrice is initialized to a very large value, and maxProfit is initialized to 0.
// The for loop iterates through each element in prices2.
// For each element, it updates minPrice and calculates potentialProfit as described in Example 1.
// The maximum profit among all potential profits is 0.
// The function returns 0, which is printed as "Example 2 Output: 0."






// JAVA

import java.util.Arrays;

class Solution {
    public int maxProfit(int[] prices) {
        int minPrice = Integer.MAX_VALUE; // Initialize the minimum price to a large value.
        int maxProfit = 0;                 // Initialize the maximum profit to 0.

        for (int price : prices) {
            // Update the minimum price if the current price is smaller.
            minPrice = Math.min(minPrice, price);

            // Calculate the potential profit if we sell at the current price.
            int potentialProfit = price - minPrice;

            // Update the maximum profit if the potential profit is greater.
            maxProfit = Math.max(maxProfit, potentialProfit);
        }

        return maxProfit;
    }
}

public class Main {
    public static void main(String[] args) {
        // Example 1
        int[] prices1 = {7, 1, 5, 3, 6, 4};
        Solution solution1 = new Solution();
        int profit1 = solution1.maxProfit(prices1);
        System.out.println("Example 1 Output: " + profit1);

        // Example 2
        int[] prices2 = {7, 6, 4, 3, 1};
        Solution solution2 = new Solution();
        int profit2 = solution2.maxProfit(prices2);
        System.out.println("Example 2 Output: " + profit2);
    }
}
