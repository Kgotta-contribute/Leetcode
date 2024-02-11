// #include <iostream>
// #include <vector>
// #include <stack>

// using namespace std;

// class Solution {
// public:
//     int evalRPN(vector<string>& tokens) {
//         stack<int> st;

//         for (const string& token : tokens) {
//             if (isOperator(token)) {
//                 int operand2 = st.top();
//                 st.pop();
//                 int operand1 = st.top();
//                 st.pop();
//                 int result = performOperation(operand1, operand2, token);
//                 st.push(result);
//             } else {
//                 st.push(stoi(token));
//             }
//         }

//         return st.top();
//     }

// private:
//     bool isOperator(const string& token) {
//         return token == "+" || token == "-" || token == "*" || token == "/";
//     }

//     int performOperation(int operand1, int operand2, const string& op) {
//         if (op == "+") {
//             return operand1 + operand2;
//         } else if (op == "-") {
//             return operand1 - operand2;
//         } else if (op == "*") {
//             return operand1 * operand2;
//         } else { // op == "/"
//             return operand1 / operand2;
//         }
//     }
// };

// int main() {
//     Solution solution;

//     // Test Case 1
//     vector<string> tokens1 = {"2", "1", "+", "3", "*"};
//     cout << "Test Case 1 Result: " << solution.evalRPN(tokens1) << endl;

//     // Test Case 2
//     vector<string> tokens2 = {"4", "13", "5", "/", "+"};
//     cout << "Test Case 2 Result: " << solution.evalRPN(tokens2) << endl;

//     // Test Case 3
//     vector<string> tokens3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
//     cout << "Test Case 3 Result: " << solution.evalRPN(tokens3) << endl;

//     return 0;
// }




#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
             // key - string  // value - Arg(int,int) & returns an int
        unordered_map<string, function<int(int, int)>> operations = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }}
        };

        for (const string& token : tokens) {
            if (operations.find(token) != operations.end()) {
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();
                int result = operations[token](operand1, operand2);
                st.push(result);
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
int main() {
    Solution solution;

    //  1
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << " 1 Result: " << solution.evalRPN(tokens1) << endl;

    //  2
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << " 2 Result: " << solution.evalRPN(tokens2) << endl;

    //  3
    vector<string> tokens3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << " 3 Result: " << solution.evalRPN(tokens3) << endl;

    return 0;
}
