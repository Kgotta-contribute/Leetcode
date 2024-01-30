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
