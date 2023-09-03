#include <vector>

int majorityElement(std::vector<int> v) {
    int candidate = v[0]; // Initialize the candidate as the first element.
    int count = 1;       // Initialize the count as 1.

    // Traverse the vector starting from the second element.
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == candidate) {
            // If the current element matches the candidate, increment the count.
            count++;
        } else {
            // If the current element is different, decrement the count.
            count--;
            if (count == 0) {
                // If the count becomes zero, update the candidate to the current element.
                candidate = v[i];
                count = 1;
            }
        }
    }

    // The final candidate should be the majority element.
    return candidate;
}

int main() {
    // Example usage:
    std::vector<int> nums = {2, 2, 1, 3, 1, 1, 3, 1, 1};
    int majority = majorityElement(nums);
    // Print the majority element
    std::cout << "Majority Element: " << majority << std::endl;

    return 0;
}
