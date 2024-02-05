#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (count[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    //  1
    Solution solution1;
    string input1 = "leetcode";
    int result1 = solution1.firstUniqChar(input1);
    cout << " 1 Result: " << result1 << endl;

    //  2
    Solution solution2;
    string input2 = "loveleetcode";
    int result2 = solution2.firstUniqChar(input2);
    cout << " 2 Result: " << result2 << endl;

    //  3
    Solution solution3;
    string input3 = "aabb";
    int result3 = solution3.firstUniqChar(input3);
    cout << " 3 Result: " << result3 << endl;

    return 0;
}
