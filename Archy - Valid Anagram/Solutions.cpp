#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false; // Anagrams must have the same length.
        }
        
        std::unordered_map<char, int> charCount;

        // Count the occurrences of characters in string s.
        for (char c : s) {
            charCount[c]++;
        }

        // Decrement the counts based on characters in string t.
        for (char c : t) {
            if (charCount.find(c) == charCount.end() || charCount[c] <= 0) {
                return false; // Character not found in s or count becomes negative.
            }
            charCount[c]--;
        }

        // Check if all character counts are zero (anagrams).
        for (const auto& pair : charCount) {
            if (pair.second != 0) {
                return false; // Character counts are not zero, not anagrams.
            }
        }

        return true; // All checks passed, s and t are anagrams.
    }
};

int main() {
    Solution solution;
    std::string s1 = "anagram";
    std::string t1 = "nagaram";
    std::string s2 = "rat";
    std::string t2 = "car";

    std::cout << boolalpha; // Print bool values as "true" or "false".
    std::cout << solution.isAnagram(s1, t1) << std::endl; // Output: true
    std::cout << solution.isAnagram(s2, t2) << std::endl; // Output: false

    return 0;
}


// Assuming s1 = "anagram" and t1 = "nagaram":

// Initialize charCount as an empty unordered map.

// Check if the lengths of s1 and t1 are equal.

// Iterate through string s1 (first loop):

// Character 'a': Increment count for 'a' in charCount, charCount = {'a': 1}.
// Character 'n': Increment count for 'n' in charCount, charCount = {'a': 1, 'n': 1}.
// Character 'a': Increment count for 'a' in charCount, charCount = {'a': 2, 'n': 1}.
// Character 'g': Increment count for 'g' in charCount, charCount = {'a': 2, 'n': 1, 'g': 1}.
// Character 'r': Increment count for 'r' in charCount, charCount = {'a': 2, 'n': 1, 'g': 1, 'r': 1}.
// Character 'a': Increment count for 'a' in charCount, charCount = {'a': 3, 'n': 1, 'g': 1, 'r': 1}.
// Character 'm': Increment count for 'm' in charCount, charCount = {'a': 3, 'n': 1, 'g': 1, 'r': 1, 'm': 1}.

// Iterate through string t1 (second loop):

// Character 'n': Decrement count for 'n' in charCount, charCount = {'a': 3, 'n': 0, 'g': 1, 'r': 1, 'm': 1}.
// Character 'a': Decrement count for 'a' in charCount, charCount = {'a': 2, 'n': 0, 'g': 1, 'r': 1, 'm': 1}.
// Character 'g': Decrement count for 'g' in charCount, charCount = {'a': 2, 'n': 0, 'g': 0, 'r': 1, 'm': 1}.
// Character 'a': Decrement count for 'a' in charCount, charCount = {'a': 1, 'n': 0, 'g': 0, 'r': 1, 'm': 1}.
// Character 'r': Decrement count for 'r' in charCount, charCount = {'a': 1, 'n': 0, 'g': 0, 'r': 0, 'm': 1}.
// Character 'a': Decrement count for 'a' in charCount, charCount = {'a': 0, 'n': 0, 'g': 0, 'r': 0, 'm': 1}.
// Iterate through the charCount map to check if all character counts are zero. They are all zero, so the function returns true, indicating that s1 and t1 are anagrams.