#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        for (const auto& word : words) {
            if (isPalindrome(word))
                return word;
        }
        return "";
    }
};

int main() {
    Solution solution;
    // Test cases
    vector<string> words1 = {"abc","car","ada","racecar","cool"};
    cout << "Output for Test Case 1: " << solution.firstPalindrome(words1) << endl;
    
    vector<string> words2 = {"notapalindrome","racecar"};
    cout << "Output for Test Case 2: " << solution.firstPalindrome(words2) << endl;
    
    vector<string> words3 = {"def","ghi"};
    cout << "Output for Test Case 3: " << solution.firstPalindrome(words3) << endl;

    return 0;
}