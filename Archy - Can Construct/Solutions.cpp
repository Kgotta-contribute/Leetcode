#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Create a hashmap to store character frequencies in the magazine
        unordered_map<char, int> charCount;

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
    string ransomNote1 = "a";
    string magazine1 = "b";
    cout << "Example 1: " << (solution.canConstruct(ransomNote1, magazine1) ? "True" : "False") << endl;

    // Example 2
    string ransomNote2 = "aa";
    string magazine2 = "ab";
    cout << "Example 2: " << (solution.canConstruct(ransomNote2, magazine2) ? "True" : "False") << endl;

    // Example 3
    string ransomNote3 = "aa";
    string magazine3 = "aab";
    cout << "Example 3: " << (solution.canConstruct(ransomNote3, magazine3) ? "True" : "False") << endl;

    return 0;
}




// string ransomNote = "aa";
// string magazine = "aab";
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