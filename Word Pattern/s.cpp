#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        istringstream ss(s);
        string word;
        
        for (char ch : pattern) {
            if (!(ss >> word)) {
                return false; // More characters in pattern than words in s
            }
            
            if (charToWord.find(ch) == charToWord.end() && wordToChar.find(word) == wordToChar.end()) {
                charToWord[ch] = word;
                wordToChar[word] = ch;
            } else {
                if (charToWord[ch] != word || wordToChar[word] != ch) {
                    return false; // Violates bijection
                }
            }
        }
        
        return !(ss >> word); // Ensure there are no extra words in s
    }
};

/*
First iteration (ch = 'a', word = "dog"):

Checks if there's a word available in s. It is true, as "dog" is available.
Checks if 'a' is not already in charToWord map and "dog" is not in wordToChar map. Both are true, so adds 'a' -> "dog" and "dog" -> 'a'.
Second iteration (ch = 'b', word = "cat"):

Checks if there's a word available in s. It is true, as "cat" is available.
Checks if 'b' is not already in charToWord map and "cat" is not in wordToChar map. Both are true, so adds 'b' -> "cat" and "cat" -> 'b'.
Third iteration (ch = 'b', word = "cat"):

Checks if there's a word available in s. It is true, as "cat" is available.
Checks if 'b' is already in charToWord map and "cat" is already in wordToChar map. Both are true, so it continues without adding new entries.
Fourth iteration (ch = 'a', word = "fish"):

Checks if there's a word available in s. It is true, as "fish" is available.
Checks if 'a' is already in charToWord map and "fish" is not in wordToChar map. Both are false, so it returns false as "fish" violates bijection.
*/

int main() {
    Solution solution;

    // 1
    cout << boolalpha << solution.wordPattern("abba", "dog cat cat dog") << endl; // Output: true

    // 2
    cout << boolalpha << solution.wordPattern("abba", "dog cat cat fish") << endl; // Output: false

    // 3
    cout << boolalpha << solution.wordPattern("aaaa", "dog cat cat dog") << endl; // Output: false

    return 0;
}
