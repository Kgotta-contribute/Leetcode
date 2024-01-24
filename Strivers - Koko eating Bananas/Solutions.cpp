// FOUND THIS BETTER APPROACH :
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
// max_element(piles.begin(), piles.end()) returns an iterator pointing to the maximum element in the range [piles.begin(), piles.end()).
//*max_element(piles.begin(), piles.end()) dereferences the iterator, giving the actual maximum element in the vector. ie max = 11 in 1st example
        while (left < right) {
            int mid = left + (right - left) / 2;

            int hoursNeeded = 0;
            for (int bananas : piles) {
                hoursNeeded += (bananas + mid - 1) / mid;
            }

            if (hoursNeeded <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main() {
    //  1
    Solution sol;
    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    int result1 = sol.minEatingSpeed(piles1, h1);
    cout << " 1 Output: " << result1 << endl;

    //  2
    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;
    int result2 = sol.minEatingSpeed(piles2, h2);
    cout << " 2 Output: " << result2 << endl;

    //  3
    vector<int> piles3 = {30, 11, 23, 4, 20};
    int h3 = 6;
    int result3 = sol.minEatingSpeed(piles3, h3);
    cout << " 3 Output: " << result3 << endl;

    return 0;
}



===================================================================




#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to check if Koko can eat all bananas within 'h' hours with given rate 'k'
bool canEatWithinHours(const vector<int>& piles, int k, int h) {
    int hours = 0;
    for (int bananas : piles) {
        hours += ceil(static_cast<double>(bananas) / k);
    }
    return hours <= h;
}

// Function to find the minimum value of 'k'
int minEatingSpeed(const vector<int>& piles, int h) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (canEatWithinHours(piles, mid, h)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    int N, h;
    cout << "Enter the number of piles: ";
    cin >> N;

    vector<int> piles(N);
    cout << "Enter the number of bananas in each pile: ";
    for (int i = 0; i < N; ++i) {
        cin >> piles[i];
    }

    cout << "Enter the time (in hours) for all the bananas to be eaten: ";
    cin >> h;

    int result = minEatingSpeed(piles, h);
    cout << "The minimum number of bananas Koko should eat per hour: " << result << endl;

    return 0;
}

/*


1. The `findMax` function finds the maximum element in the vector `v`. It is used to determine the upper bound for the binary search. The variable `high` is initialized with the maximum element of the vector.

2. The `calculateTotalHours` function calculates the total hours required to eat all the bananas in the given vector `v` at a given hourly eating rate. It uses the `ceil` function to round up the division result to the nearest integer, as the monkey can only eat complete bananas, not fractions.

3. In the `minimumRateToEatBananas` function, binary search is applied to find the minimum eating rate required for Koko to eat all the bananas within `h` hours. The binary search is performed between `low` and `high`, where `low` is initialized to 1 (minimum possible eating rate), and `high` is initialized to the maximum element in the vector.

4. The binary search iterates until `low` is less than or equal to `high`.

5. In each iteration of the binary search, the middle value `mid` is calculated as the average of `low` and `high`.

6. The `totalH` variable is set to the total hours required to eat all bananas at the current `mid` eating rate, using the `calculateTotalHours` function.

7. If the `totalH` is less than or equal to the given `h`, it means Koko can eat all the bananas within `h` hours at the current eating rate `mid`. Therefore, the upper bound `high` of the binary search is updated to `mid - 1`.

8. If the `totalH` is greater than `h`, it means Koko cannot eat all the bananas within `h` hours at the current eating rate `mid`. Therefore, the lower bound `low` of the binary search is updated to `mid + 1`.

9. The binary search continues, narrowing down the search space until `low` becomes greater than `high`.

10. Once the binary search ends, the `low` value represents the minimum eating rate at which Koko can eat all the bananas within `h` hours.

11. The final result, the minimum eating rate `low`, is returned by the `minimumRateToEatBananas` function and printed in the `main` function.

Let's walk through an example using the given input `{7, 15, 6, 3}` and `h = 8`:

- Initially, `low = 1` and `high = 15` (maximum element in the vector).
- The binary search starts.
- First iteration: `mid = (1 + 15) / 2 = 8`.
  - The total hours required at `mid = 8` is calculated: `totalH = 1 + 2 + 1 + 1 = 5`.
  - Since `totalH (5)` is less than `h (8)`, update `high = mid - 1 = 8 - 1 = 7`.
- Second iteration: `mid = (1 + 7) / 2 = 4`.
  - The total hours required at `mid = 4` is calculated: `totalH = 2 + 4 + 2 + 1 = 9`.
  - Since `totalH (9)` is greater than `h (8)`, update `low = mid + 1 = 4 + 1 = 5`.
- Third iteration: `mid = (5 + 7) / 2 = 6`.
  - The total hours required at `mid = 6` is calculated: `totalH = 2 + 3 + 1 + 1 = 7`.
  - Since `totalH (7)` is greater than `h (8)`, update `low = mid + 1 = 6 + 1 = 7`.
- Fourth iteration: `mid = (7 + 7) / 2 = 7`.
  - The total hours required at `mid = 7` is calculated: `totalH = 2 + 3 + 1 + 1 = 7`.
  - Since `totalH (7)` is equal to `h (8)`, update `high = mid - 1 = 7 - 1 = 6`.
- The binary search ends, and the result is `low = 7`, which means Koko should eat at least 7 bananas per hour to finish all the bananas within 8 hours.


*/













/*

#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    int low = 1, high = findMax(v);

    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);
        if (totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}

*/