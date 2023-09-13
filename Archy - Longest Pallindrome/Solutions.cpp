#include <iostream>
#include <unordered_map>

class Solution {
public:
    int longestPalindrome(std::string s) {
        std::unordered_map<char, int> charCount;

        // Count the frequency of each character in the string
        for (char ch : s) {
            charCount[ch]++;
        }

        int palindromeLength = 0;
        bool hasOddCount = false;

        // Calculate the length of the longest palindrome
        for (const auto& pair : charCount) {
            if (pair.second % 2 == 0) {
                palindromeLength += pair.second; // Even count contributes directly to the length
            } else {
                palindromeLength += pair.second - 1; // Use an even count (if available)
                hasOddCount = true; // Flag that there is at least one character with an odd count
            }
        }

        // If there's at least one character with an odd count, add 1 to the length
        if (hasOddCount) {
            palindromeLength++;
        }

        return palindromeLength;
    }
};

int main() {
    Solution solution;

    // Example 1
    std::string s1 = "abccccdd";
    std::cout << "Example 1: " << solution.longestPalindrome(s1) << std::endl;

    // Example 2
    std::string s2 = "a";
    std::cout << "Example 2: " << solution.longestPalindrome(s2) << std::endl;

    return 0;
}







// Iteration 1:

// Initialize an empty charCount hashmap.
// Start with the string "abccccdd".
// Iteration 2:

// Iterate through the string and count character frequencies:
// 'a' appears 1 time.
// 'b' appears 1 time.
// 'c' appears 4 times.
// 'd' appears 2 times.
// Iteration 3:

// Initialize palindromeLength to 0.
// Initialize hasOddCount to false.
// Iteration 4:

// Process each character count:
// For 'a' (count = 1), it's an odd count. Subtract 1 and add it to palindromeLength.
// palindromeLength becomes 1.
// Set hasOddCount to true.
// Iteration 5:

// For 'b' (count = 1), it's an odd count. Subtract 1 and add it to palindromeLength.
// palindromeLength becomes 2.
// hasOddCount remains true.
// Iteration 6:

// For 'c' (count = 4), it's an even count. Add it directly to palindromeLength.
// palindromeLength becomes 6.
// Iteration 7:

// For 'd' (count = 2), it's an even count. Add it directly to palindromeLength.
// palindromeLength becomes 8.
// Iteration 8:

// Since there's at least one character with an odd count, add 1 to palindromeLength.
// palindromeLength becomes 9.
// The final result is palindromeLength = 9, which means the length of the longest palindrome that can be built from the string "abccccdd" is 9.













