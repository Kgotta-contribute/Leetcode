#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1}; // 1-indexed array
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
        // It is guaranteed that there is exactly one solution, so no need to handle the case where no solution is found.
        return {}; 
    }
};

int main() {
    Solution solution;

    //  1
    vector<int> numbers1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(numbers1, target1);
    cout << " 1 Output: [" << result1[0] << ", " << result1[1] << "]" << endl;

    //  2
    vector<int> numbers2 = {2, 3, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(numbers2, target2);
    cout << " 2 Output: [" << result2[0] << ", " << result2[1] << "]" << endl;

    //  3
    vector<int> numbers3 = {-1, 0};
    int target3 = -1;
    vector<int> result3 = solution.twoSum(numbers3, target3);
    cout << " 3 Output: [" << result3[0] << ", " << result3[1] << "]" << endl;

    return 0;
}

================================================================

// JAVA
import java.util.Arrays;

class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int left = 0;
        int right = numbers.length - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return new int[]{left + 1, right + 1};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return new int[0];
    }
}

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // 1
        int[] numbers1 = {2, 7, 11, 15};
        int target1 = 9;
        int[] result1 = solution.twoSum(numbers1, target1);
        System.out.println(" 1 Output: " + Arrays.toString(result1));

        // 2
        int[] numbers2 = {2, 3, 4};
        int target2 = 6;
        int[] result2 = solution.twoSum(numbers2, target2);
        System.out.println(" 2 Output: " + Arrays.toString(result2));

        // 3
        int[] numbers3 = {-1, 0};
        int target3 = -1;
        int[] result3 = solution.twoSum(numbers3, target3);
        System.out.println(" 3 Output: " + Arrays.toString(result3));
    }
}
