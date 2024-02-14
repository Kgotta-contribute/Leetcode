// might take lil more time for me
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
    
    void backtrack(vector<string>& result, string current, int open, int close, int max) {
        if (current.size() == max * 2) {
            result.push_back(current);
            return;
        }
        
        if (open < max)
            backtrack(result, current + '(', open + 1, close, max);
        if (close < open)
            backtrack(result, current + ')', open, close + 1, max);
    }
};
/*
(()()) and (())().

For (()()):

We start with an empty result vector.
We call backtrack(result, "", 0, 0, 3).
Iteration:

backtrack(result, "(", 1, 0, 3)
backtrack(result, "((", 2, 0, 3)
backtrack(result, "(()", 2, 1, 3)
backtrack(result, "(()(", 3, 1, 3)
backtrack(result, "(()()", 3, 2, 3)
For (())():

We start with an empty result vector.
We call backtrack(result, "", 0, 0, 3).
Iteration:

backtrack(result, "(", 1, 0, 3)
backtrack(result, "((", 2, 0, 3)
backtrack(result, "(()", 2, 1, 3)
backtrack(result, "(())", 2, 2, 3)
backtrack(result, "(())(", 3, 2, 3)
backtrack(result, "(())()", 3, 3, 3)
*/