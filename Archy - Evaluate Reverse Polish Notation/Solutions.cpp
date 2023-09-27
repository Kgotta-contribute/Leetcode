//harder one here !!

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        int operand1, operand2;

        for (const string& token : tokens) {
            if (token == "+") {
                operand2 = operands.top();
                operands.pop();
                operand1 = operands.top();
                operands.pop();
                operands.push(operand1 + operand2);
            } else if (token == "-") {
                operand2 = operands.top();
                operands.pop();
                operand1 = operands.top();
                operands.pop();
                operands.push(operand1 - operand2);
            } else if (token == "*") {
                operand2 = operands.top();
                operands.pop();
                operand1 = operands.top();
                operands.pop();
                operands.push(operand1 * operand2);
            } else if (token == "/") {
                operand2 = operands.top();
                operands.pop();
                operand1 = operands.top();
                operands.pop();
                operands.push(operand1 / operand2);
            } else {
                operands.push(stoi(token));
            }
        }

        return operands.top();
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << "Example 1: " << solution.evalRPN(tokens1) << endl; // Output: 9

    // Example 2
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << "Example 2: " << solution.evalRPN(tokens2) << endl; // Output: 6

    // Example 3
    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << "Example 3: " << solution.evalRPN(tokens3) << endl; // Output: 22

    return 0;
}
