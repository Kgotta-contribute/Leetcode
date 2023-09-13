#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        // Create a hashmap to store character frequencies in the magazine
        std::unordered_map<char, int> charCount;

        // Count character frequencies in the magazine
        for (char ch : magazine) {
            charCount[ch]++;
        }

        // Check if you can construct the ransom note
        for (char ch : ransomNote) {
            if (charCount.find(ch) != charCount.end() && charCount[ch] > 0) {
                // If the character is in the magazine and has a positive count, use it
                charCount[ch]--;
            } else {
                // If the character is not in the magazine or has been used up, return false
                return false;
            }
        }

        // If you successfully used all characters in the ransom note, return true
        return true;
    }
};

int main() {
    Solution solution;

    // Example 1
    std::string ransomNote1 = "a";
    std::string magazine1 = "b";
    std::cout << "Example 1: " << (solution.canConstruct(ransomNote1, magazine1) ? "True" : "False") << std::endl;

    // Example 2
    std::string ransomNote2 = "aa";
    std::string magazine2 = "ab";
    std::cout << "Example 2: " << (solution.canConstruct(ransomNote2, magazine2) ? "True" : "False") << std::endl;

    // Example 3
    std::string ransomNote3 = "aa";
    std::string magazine3 = "aab";
    std::cout << "Example 3: " << (solution.canConstruct(ransomNote3, magazine3) ? "True" : "False") << std::endl;

    return 0;
}




// std::string ransomNote = "aa";
// std::string magazine = "aab";
// Here's the step-by-step iteration of the canConstruct function:

// Iteration 1:

// Initialize an empty charCount hashmap.
// Start with ransomNote character 'a'.
// Check if 'a' exists in charCount. It doesn't.
// Increment the count for 'a' in charCount. charCount['a'] becomes 1.
// Iteration 2:

// Move to the next character 'a' in ransomNote.
// Check if 'a' exists in charCount. It does.
// Decrement the count for 'a' in charCount. charCount['a'] becomes 0.
// Iteration 3:

// Move to the next character 'b' in ransomNote.
// Check if 'b' exists in charCount. It doesn't.
// Return false because 'b' cannot be found in charCount.
// At this point, the function exits early with a result of false. It means you cannot construct the ransom note "aa" using the characters in the magazine "aab" because there's a character ('b') in the ransom note that is not present in the magazine.