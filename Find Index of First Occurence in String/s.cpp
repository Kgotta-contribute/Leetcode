#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackLen = haystack.length();
        int needleLen = needle.length();
        if (needleLen == 0) {
            return 0;
        }
        for (int i = 0; i <= haystackLen - needleLen; i++) {
            int j;
            for (j = 0; j < needleLen; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == needleLen) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;

    //  1
    ::string haystack1 = "sadbutsad";
    string needle1 = "sad";
    cout << " 1 Result: " << solution.strStr(haystack1, needle1) << endl;

    //  2
    string haystack2 = "leetcode";
    string needle2 = "leeto";
    cout << " 2 Result: " << solution.strStr(haystack2, needle2) << endl;

    return 0;
}



/*
 haystack = "sadbutsad" and needle = "sad":

Iteration 1 (i=0): Compare "sad" with "sad" (match found, returns 0).
Iteration 2 (i=1): Compare "adb" with "sad" (no match).
Iteration 3 (i=2): Compare "dbu" with "sad" (no match).
Iteration 4 (i=3): Compare "but" with "sad" (no match).
Iteration 5 (i=4): Compare "uts" with "sad" (no match).
Iteration 6 (i=5): Compare "tsa" with "sad" (no match).
Iteration 7 (i=6): Compare "sad" with "sad" (match found, returns 6).
*/