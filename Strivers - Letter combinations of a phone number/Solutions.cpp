#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        
        vector<string> digitToLetters = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        backtrack(digits, 0, "", result, digitToLetters);
        return result;
    }
    
    void backtrack(const string& digits, int index, string current, vector<string>& result, const vector<string>& digitToLetters) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        int digit = digits[index] - '0';
        for (char letter : digitToLetters[digit]) {
            backtrack(digits, index + 1, current + letter, result, digitToLetters);
        }
    }
};

int main() {
    Solution solution;

    string input1 = "23";
    vector<string> result1 = solution.letterCombinations(input1);
    cout << "Input: \"" << input1 << "\"" << endl;
    cout << "Output: [";
    for (const string& str : result1) {
        cout << "\"" << str << "\", ";
    }
    cout << "]" << endl;

    string input2 = "";
    vector<string> result2 = solution.letterCombinations(input2);
    cout << "Input: \"" << input2 << "\"" << endl;
    cout << "Output: [";
    for (const string& str : result2) {
        cout << "\"" << str << "\", ";
    }
    cout << "]" << endl;

    string input3 = "2";
    vector<string> result3 = solution.letterCombinations(input3);
    cout << "Input: \"" << input3 << "\"" << endl;
    cout << "Output: [";
    for (const string& str : result3) {
        cout << "\"" << str << "\", ";
    }
    cout << "]" << endl;

    return 0;
}
