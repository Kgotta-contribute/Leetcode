//Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the 
//letters from magazine and false otherwise.

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

    string ransomNote1 = "ac";
    string magazine1 = "babc";
    cout << "Example 1: " << (solution.canConstruct(ransomNote1, magazine1) ? "True" : "False") << endl;

    string ransomNote2 = "aa";
    string magazine2 = "ab";
    cout << "Example 2: " << (solution.canConstruct(ransomNote2, magazine2) ? "True" : "False") << endl;

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









// JAVA CODE:


import java.util.HashMap;

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        // Create a hashmap to store character frequencies in the magazine
        HashMap<Character, Integer> charCount = new HashMap<>();

        // Count character frequencies in the magazine
        for (char ch : magazine.toCharArray()) {
            charCount.put(ch, charCount.getOrDefault(ch, 0) + 1);
        }

        // Check if you can construct the ransom note
        for (char ch : ransomNote.toCharArray()) {
            if (charCount.containsKey(ch) && charCount.get(ch) > 0) {
                // If the character is in the magazine and has a positive count, use it
                charCount.put(ch, charCount.get(ch) - 1);
            } else {
                // If the character is not in the magazine or has been used up, return false
                return false;
            }
        }

        // If you successfully used all characters in the ransom note, return true
        return true;
    }
}

public class MyClass {
    public static void main(String[] args) {
        Solution solution = new Solution();

        String ransomNote1 = "ac";
        String magazine1 = "babc";
        System.out.println("Example 1: " + (solution.canConstruct(ransomNote1, magazine1) ? "True" : "False"));

        String ransomNote2 = "aa";
        String magazine2 = "ab";
        System.out.println("Example 2: " + (solution.canConstruct(ransomNote2, magazine2) ? "True" : "False"));

        String ransomNote3 = "aa";
        String magazine3 = "aab";
        System.out.println("Example 3: " + (solution.canConstruct(ransomNote3, magazine3) ? "True" : "False"));
    }
}
