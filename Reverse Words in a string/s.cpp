#include <sstream>
#include <vector>
#include <algorithm>

class Solution {
public:
    string reverseWords(string s) {
        // Use a stringstream to extract words from the input string
        stringstream ss(s);
        string word;
        vector<string> words;

        // Extract words and store them in a vector
        while (ss >> word) {
            words.push_back(word);
        }

        // Reverse the order of words in the vector
        reverse(words.begin(), words.end());

        // Concatenate the reversed words with a single space
        string result;
        for (const string& w : words) {
            result += w + " ";
        }

        // Remove the trailing space and return the result
        result.pop_back();
        return result;
    }
};
