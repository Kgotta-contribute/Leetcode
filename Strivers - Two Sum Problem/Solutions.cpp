#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) 
        {
            if (mp.find(target - nums[i]) == mp.end())
                mp[nums[i]] = i;            // eg : (mp[2] = 0)
            else
                return {mp[target - nums[i]], i};
        }
        return {-1, -1};
    }
};

int main() {

    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    Solution solution1;
    vector<int> result1 = solution1.twoSum(nums1, target1);
    cout << "Example 1 Output: [" << result1[0] << ", " << result1[1] << "]\n";

    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    Solution solution2;
    vector<int> result2 = solution2.twoSum(nums2, target2);
    cout << "Example 2 Output: [" << result2[0] << ", " << result2[1] << "]\n";

    vector<int> nums3 = {3, 2,1,3};
    int target3 = 6;
    Solution solution3;
    vector<int> result3 = solution3.twoSum(nums3, target3);
    cout << "Example 3 Output: [" << result3[0] << ", " << result3[1] << "]\n";

    return 0;
}



// Suppose we have the input twoSum([2, 7, 11, 15], 9).

// unordered_map<int, int> mp; An empty unordered map mp is created to store elements from the nums 
//array as keys and their indices as values. Initially, mp is empty.

// for (int i = 0; i < nums.size(); i++): This for loop is initiated to iterate through the elements of the nums 
//array. The loop starts with i = 0 and continues until i reaches the size of the nums array.

// Inside the loop, let's break down the logic step by step for each iteration:

// Iteration 1 (i = 0):
// Current element: nums[i] is 2.
// Complement calculation: target - nums[i] is 9 - 2, which is 7.
// Check if 7 exists in the map (mp.find(7) == mp.end()): Since mp is empty, the condition is true.
// Action taken:
// Add 2 to the map with an index of 0 (mp[2] = 0). This means we've seen the number 2 at index 0.

// Iteration 2 (i = 1):
// Current element: nums[i] is 7.
// Complement calculation: target - nums[i] is 9 - 7, which is 2.
// Check if 2 exists in the map (mp.find(2) == mp.end()): Since 2 was added to the map in the previous iteration, 
//the condition is false.
// Action taken:
// Return a vector containing the indices of the two numbers. The first index is mp[2], which is 0 (the index of 
//the previously seen 2), and the second index is 1 (the current i value). So, it returns [0, 1] as the result, 
//indicating that the numbers at indices 0 and 1 (2 and 7) add up to 9.
// The function exits after returning [0, 1] as the output.

//  mp is used to keep track of elements from the nums array and their corresponding 
//  indices. The loop iterates through the nums array, and for each element, it calculates 
//  the complement needed to reach the target value. If the complement is not found in 
//  the map (indicating that no previous element can be used to reach the target), 
//  the current element is added to the map with its index. If the complement is found 
//  in the map, it means a pair of elements has been found whose sum equals the target 
//  value, and the function returns the indices of these two elements. 









// JAVA


import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            if (!map.containsKey(target - nums[i])) {
                map.put(nums[i], i);
            } else {
                return new int[]{map.get(target - nums[i]), i};
            }
        }
        return new int[]{-1, -1};
    }
}

public class Main {
    public static void main(String[] args) {
        
        int[] nums1 = {2, 7, 11, 15};
        int target1 = 9;
        Solution solution1 = new Solution();
        int[] result1 = solution1.twoSum(nums1, target1);
        System.out.println("Example 1 Output: [" + result1[0] + ", " + result1[1] + "]");

        int[] nums2 = {3, 2, 4};
        int target2 = 6;
        Solution solution2 = new Solution();
        int[] result2 = solution2.twoSum(nums2, target2);
        System.out.println("Example 2 Output: [" + result2[0] + ", " + result2[1] + "]");

        int[] nums3 = {3, 2, 1, 3};
        int target3 = 6;
        Solution solution3 = new Solution();
        int[] result3 = solution3.twoSum(nums3, target3);
        System.out.println("Example 3 Output: [" + result3[0] + ", " + result3[1] + "]");
    }
}
