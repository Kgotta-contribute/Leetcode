#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }

    string prefix = strs[0];

    for (int i = 1; i < strs.size(); ++i) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) {
                return "";
            }
        }
    }

    return prefix;
}

int main() {
    vector<string> input1 = {"flower", "flow", "flight"};
    cout << "Output 1: " << longestCommonPrefix(input1) << endl;

    vector<string> input2 = {"dog", "racecar", "car"};
    cout << "Output 2: " << longestCommonPrefix(input2) << endl;

    vector<string> input3 = {"apple", "ape", "app"};
    cout << "Output 3: " << longestCommonPrefix(input3) << endl;

    vector<string> input4 = {"prefix", "prelude", "premier"};
    cout << "Output 4: " << longestCommonPrefix(input4) << endl;

    vector<string> input5 = {"abcd", "abcde", "abcdef"};
    cout << "Output 5: " << longestCommonPrefix(input5) << endl;

    return 0;
}
