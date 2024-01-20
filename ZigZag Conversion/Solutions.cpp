#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        vector<string> rows(min(numRows, int(s.length())));
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;

            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            currentRow += goingDown ? 1 : -1;
        }

        string result;
        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Example 1
    string result1 = solution.convert("PAYPALISHIRING", 3);
    cout << "Example 1: " << result1 << endl;

    // Example 2
    string result2 = solution.convert("PAYPALISHIRING", 4);
    cout << "Example 2: " << result2 << endl;

    // Example 3
    string result3 = solution.convert("A", 1);
    cout << "Example 3: " << result3 << endl;

    return 0;
}
