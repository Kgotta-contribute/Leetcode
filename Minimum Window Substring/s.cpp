#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> charCount;
        for (char c : t) {
            charCount[c]++;
        }
        int left = 0, right = 0, minLength = INT_MAX, minLeft = 0, count = t.length();
        while (right < s.length()) {
            if (charCount[s[right]] > 0) {
                count--;
            }
            charCount[s[right]]--;
            right++;

            while (count == 0) {
                if (right - left < minLength) {
                    minLength = right - left;
                    minLeft = left;
                }

                charCount[s[left]]++;
                if (charCount[s[left]] > 0) {
                    count++;
                }
                left++;
            }
        }
        return (minLength == INT_MAX) ? "" : s.substr(minLeft, minLength);
    }
};

int main() {
    Solution solution;

    //  1
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << " 1: " << solution.minWindow(s1, t1) << endl;

    //  2
    string s2 = "a";
    string t2 = "a";
    cout << " 2: " << solution.minWindow(s2, t2) << endl;

    //  3
    string s3 = "a";
    string t3 = "aa";
    cout << " 3: " << solution.minWindow(s3, t3) << endl;

    return 0;
}


// #include <iostream>
// #include <unordered_map>
// using namespace std;
// class Solution {
// public:
// string minWindow(string s, string t) {
//     unordered_map<char, int> target, window;
//     int left = 0, right = 0;
//     int formed = 0, required = t.length();
//     int minLen = INT_MAX, minStart = -1;
    
//     // Count the characters in t
//     for (char c : t)
//         target[c]++;
    
//     while (right < s.length()) {
//         // Expand the window
//         char c = s[right];
//         window[c]++;
        
//         // Check if the current character is in t and its count is satisfied
//         if (target.count(c) && window[c] <= target[c])
//             formed++;
        
//         // Contract the window if all characters in t are included
//         while (left <= right && formed == required) {
//             // Update the minimum window length and start position
//             if (right - left + 1 < minLen) {
//                 minLen = right - left + 1;
//                 minStart = left;
//             }
            
//             // Remove the leftmost character from the window
//             char leftChar = s[left];
//             window[leftChar]--;
            
//             // Check if the removed character affects the formed count
//             if (target.count(leftChar) && window[leftChar] < target[leftChar])
//                 formed--;
            
//             // Move the left pointer to the right
//             left++;
//         } 
        
//         // Move the right pointer to the right
//         right++;
//     }
    
//     return (minStart == -1) ? "" : s.substr(minStart, minLen);
// }
// };

// int main() {
//     string s = "ADOBECODEBANC";
//     string t = "ABC";
    
//     string result = minWindow(s, t);
//     cout << "Minimum window substring: " << result << endl;
    
//     return 0;
// }