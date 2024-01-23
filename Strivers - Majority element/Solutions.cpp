#include <vector>
#include<iostream>
using namespace std;
int majorityElement(vector<int> v) {
    int candidate = v[0]; // Initialize the candidate as the first item.
    int count = 1;       // Initialize the count as 1.

    // Traverse the vector starting from the second item.
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == candidate) {
            // If the current item matches the candidate, increment the count.
            count++;
        } else {
            // If the current item is different, decrement the count.
            count--;
            if (count == 0) {
                // If the count becomes zero, update the candidate to the current item.
                candidate = v[i];
                count = 1;
            }
        }
    }

    // The final candidate should be the majority item.
    return candidate;
}

int main() {
    // Example usage:
    vector<int> nums = {2, 2, 1, 3, 1, 1, 3, 1, 1};
    int majority = majorityitem(nums);
    // Print the majority item
    cout << "Majority item: " << majority << endl;

    return 0;
}


//or


#include <vector>
#include <unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;

        // Count the occurrences of each item
        for (int num : nums) {
            counts[num]++;
        }

        // Find the item with frequency greater than n/2
        int n = nums.size();
        for (const auto& entry : counts) {
            if (entry.second > n / 2) {
                return entry.first;
            }
        }

        // The majority item always exists in the array, so this return is not reached.
        return -1;
    }
};


/*
for (const auto& entry : counts) {

auto: In C++, auto is used for automatic type inference. Here, it is used to automatically deduce the type of the elements in the counts map, making it convenient and flexible.
const: This keyword indicates that the loop variable entry is constant and cannot be modified within the loop.
&: This ampersand (&) is used to create a reference to each element in the map. Using a reference allows the loop to work directly with the elements in the map without making unnecessary copies.
if (entry.second > nums.size() / 3) {

entry: Represents each key-value pair in the counts map during each iteration of the loop.
entry.second: Refers to the value associated with the key in the map, which is the count of occurrences of that element in the nums vector.
nums.size() / 3: The condition checks whether the count of occurrences (entry.second) is greater than one-third of the total size of the nums vector. 
*/