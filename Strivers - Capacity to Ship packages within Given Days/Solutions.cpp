#include <iostream>
#include <vector>
#include <numeric> // for accumulate
#include <algorithm> // for max_element

using namespace std;

bool canShipWithinDays(vector<int>& weights, int d, int capacity) {
    int days_needed = 1;
    int curr_weight = 0;

    for (int weight : weights) {
        if (curr_weight + weight > capacity) {
            days_needed++;
            curr_weight = weight;
        } else {
            curr_weight += weight;
        }
    }

    return days_needed <= d;
}

int shipWithinDays(vector<int>& weights, int d) {
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0) + 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (canShipWithinDays(weights, d, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    vector<int> weights1 = {5, 4, 5, 2, 3, 4, 5, 6};
    int d1 = 5;
    cout << "Example 1: " << shipWithinDays(weights1, d1) << endl; // Output: 9

    vector<int> weights2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int d2 = 1;
    cout << "Example 2: " << shipWithinDays(weights2, d2) << endl; // Output: 55

    return 0;
}

/*


1. `canShipWithinDays` function:
   This function takes three arguments:
   - `weights`: A reference to the vector of weights.
   - `d`: An integer representing the number of days.
   - `capacity`: An integer representing the current weight capacity being tested.

   The purpose of this function is to simulate the process of shipping the packages with the given weight capacity (`capacity`) and check if it can be done within the given number of days (`d`).

   It starts by initializing `days_needed` to 1 and `curr_weight` to 0. The variables `days_needed` and `curr_weight` keep track of the number of days needed and the current weight being processed on a particular day, respectively.

   It then iterates through the `weights` vector using a range-based for loop. For each weight in the vector, it checks if adding the weight to the current weight (`curr_weight`) exceeds the current capacity (`capacity`). If it does, that means the current day's capacity is exhausted, and it will require an additional day (`days_needed++`). The `curr_weight` is then reset to the current weight as the new day starts with a fresh weight.

   If adding the weight doesn't exceed the capacity, it simply adds the weight to the current weight (`curr_weight += weight`) for the ongoing day.

   After processing all the weights, the function checks if the total number of days needed (`days_needed`) is less than or equal to the given number of days (`d`). If this condition is true, it returns `true`, indicating that the packages can be shipped within the given number of days with the given capacity. Otherwise, it returns `false`.

2. `shipWithinDays` function:
   This function takes two arguments:
   - `weights`: A reference to the vector of weights.
   - `d`: An integer representing the number of days.

   The purpose of this function is to find the minimum weight capacity required to ship all the packages within the given number of days (`d`).

   It initializes two variables `left` and `right`. The `left` variable is set to the maximum weight in the `weights` vector (calculated using `max_element`), and the `right` variable is set to the sum of all weights in the `weights` vector plus 1 (calculated using `accumulate`).

   Then, it enters a binary search loop with the condition `left < right`. In each iteration, it calculates the middle value (`mid`) of the `left` and `right` boundaries.

   The `canShipWithinDays` function is called with the `weights`, `d`, and `mid` arguments to check if it's possible to ship all the packages within `d` days with the capacity `mid`. If it returns `true`, that means the capacity is sufficient, so the `right` boundary is updated to `mid`, narrowing the search range. Otherwise, if it returns `false`, the `left` boundary is updated to `mid + 1`, eliminating the possibilities below `mid`.

   The binary search continues until the `left` and `right` boundaries converge (i.e., `left >= right`).

   Finally, the function returns the `left` boundary value, which represents the minimum weight capacity required to ship all the packages within the given number of days (`d`).

3. `main` function:
   The `main` function demonstrates the usage of the `shipWithinDays` function with two examples.

   - Example 1: The `weights1` vector contains weights {5, 4, 5, 2, 3, 4, 5, 6}, and the number of days `d1` is 5. The output of `shipWithinDays(weights1, d1)` is 9, which means the minimum weight capacity needed to ship all packages within 5 days is 9.
   - Example 2: The `weights2` vector contains weights {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, and the number of days `d2` is 1. The output of `shipWithinDays(weights2, d2)` is 55, which means the minimum weight capacity needed to ship all packages within 1 day is 55.

The binary search technique employed here helps efficiently find the minimum weight capacity by reducing the search space in each iteration. This approach is effective for this problem as it exploits the property that if a certain capacity is sufficient to ship the packages within `d` days, any capacity greater than that will also be sufficient. Hence, the binary search algorithm can quickly find the optimal capacity in logarithmic time complexity.

*/