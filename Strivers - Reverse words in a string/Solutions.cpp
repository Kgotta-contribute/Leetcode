// JAVA CODE :- 

// Input String: " the quick brown fox "
// After s.trim(): "the quick brown fox" -> removves spaces
// After split("\\s+"): ["the", "quick", "brown", "fox"] -> puts into token

class Solution {
    public String reverseWords(String s) {
        // Trim the string and split it by one or more spaces
        String[] words = s.trim().split("\\s+");

        // Use a StringBuilder to build the result
        StringBuilder reversed = new StringBuilder();

        // Iterate from the end of the array to the beginning
        for (int i = words.length - 1; i >= 0; i--) {
            if (i < words.length - 1) {
                reversed.append(" ");  // Add a space between words
            }
            reversed.append(words[i]);
        }

        return reversed.toString();
    }
}



=================================================================================================



// CPP
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> words;
        string word;

        // Step 1: Read words from the string stream
        while (iss >> word) {
            words.push_back(word);
        }

        // Step 2: Reverse the words in the vector
        reverse(words.begin(), words.end());

        // Step 3: Join the reversed words into a single string
        string result;
        for (size_t i = 0; i < words.size(); ++i) {
            if (i > 0) {
                result += " ";
            }
            result += words[i];
        }

        return result;
    }
};
/*
Instead of size_t we can use 'int' but for below reason use size_t
Non-Negative: size_t is unsigned, so it inherently avoids negative values, which is useful for sizes and indices.
Size and Range: size_t is designed to be able to represent the maximum size of any object in memory. 
This is useful when dealing with large data structures.*/




// Python
class Solution:
    def reverseWords(self, s: str) -> str:
        # Step 1: Trim leading and trailing spaces and split by any whitespace
        words = s.strip().split()
        
        # Step 2: Reverse the list of words and join them with a single space
        reversed_words = ' '.join(reversed(words))
        
        return reversed_words
