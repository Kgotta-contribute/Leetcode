#include <iostream>
#include <string>

class Solution {
public:
    bool isValid(std::string s) 
    {
        int len = s.length();
        char* stack = new char[len];
        int top = 0;

        for (char c : s) 
        {
            if (c == '(' || c == '[' || c == '{') 
            {
                stack[top++] = c;
            } 
            else if (c == ')' || c == ']' || c == '}') 
            {
                if (top == 0 || !isValidPair(stack[--top], c)) 
                {
                    delete[] stack;
                    return false;
                }
            }
        }

        bool result = (top == 0);
        delete[] stack;
        return result;
    }

private:
    bool isValidPair(char open, char close) 
    {
        return (open == '(' && close == ')') ||
               (open == '[' && close == ']') ||
               (open == '{' && close == '}');
    }
};

int main() {
    Solution solution;
    std::string s1 = "()";
    std::string s2 = "()[]{}";
    std::string s3 = "(]";

    std::cout << solution.isValid(s1) << std::endl;  // Output: 1 (True)
    std::cout << solution.isValid(s2) << std::endl;  // Output: 1 (True)
    std::cout << solution.isValid(s3) << std::endl;  // Output: 0 (False)

    return 0;
}




// #include <iostream>
// #include <stack>
// #include <string>

// class Solution {
// public:
//     bool isValid(std::string s) {
//         // Create a stack to store opening brackets encountered.
//         std::stack<char> stack;
        
//         // Create a mapping of closing brackets to their corresponding opening brackets.
//         std::unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};

//         // Iterate through each character in the input string.
//         for (char c : s) {
//             if (mapping.find(c) != mapping.end()) {
//                 // If the current character is a closing bracket:
//                 // 1. Check if the stack is not empty.
//                 // 2. Check if the top of the stack matches the expected opening bracket for 'c'.
//                 if (stack.empty() || stack.top() != mapping[c]) {
//                     return false; // If either condition is not met, return false.
//                 }
//                 stack.pop(); // Pop the corresponding opening bracket from the stack.
//             } else {
//                 // If the current character is not a closing bracket, it's an opening bracket.
//                 stack.push(c); // Push it onto the stack.
//             }
//         }

//         // After processing all characters in the input string,
//         // the stack should be empty if all brackets are balanced.
//         return stack.empty();
//     }
// };

// int main() {
//     Solution solution;
//     std::string s1 = "()";
//     std::string s2 = "()[]{}";
//     std::string s3 = "(]";

//     // Test the isValid function with example strings and print the results.
//     std::cout << solution.isValid(s1) << std::endl;  // Output: 1 (True)
//     std::cout << solution.isValid(s2) << std::endl;  // Output: 1 (True)
//     std::cout << solution.isValid(s3) << std::endl;  // Output: 0 (False)

//     return 0;
// }



// #include <iostream>
// #include <stack>
// #include <string>

// class Solution {
// public:
//     bool isValid(std::string s) {
//         std::stack<char> stack;
//         std::unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};

//         for (char c : s) {
//             if (mapping.find(c) != mapping.end()) {
//                 char topElement = stack.empty() ? '#' : stack.top();
//                 if (topElement != mapping[c]) {
//                     return false;
//                 }
//                 stack.pop();
//             } else {
//                 stack.push(c);
//             }
//         }

//         return stack.empty();
//     }
// };

// int main() {
//     Solution solution;
//     std::string s1 = "()";
//     std::string s2 = "()[]{}";
//     std::string s3 = "(]";

//     std::cout << solution.isValid(s1) << std::endl;  // Output: 1 (True)
//     std::cout << solution.isValid(s2) << std::endl;  // Output: 1 (True)
//     std::cout << solution.isValid(s3) << std::endl;  // Output: 0 (False)

//     return 0;
// }
// Input string: "()[]{}"

// Start with an empty stack and an empty string.
// Stack: ``

// Iterate through the characters in the input string:

// Character '(' is encountered:

// It's an opening bracket, so it's pushed onto the stack.
// Stack: (
// Character ')' is encountered:

// It's a closing bracket.
// The stack is not empty, so we check if the top of the stack matches the expected opening bracket for ')', which is '('. They match.
// The top of the stack is popped.
// Stack: ``
// Character '[' is encountered:

// It's an opening bracket, so it's pushed onto the stack.
// Stack: [
// Character ']' is encountered:

// It's a closing bracket.
// The stack is not empty, so we check if the top of the stack matches the expected opening bracket for ']', which is '['. They match.
// The top of the stack is popped.
// Stack: ``
// Character '{' is encountered:

// It's an opening bracket, so it's pushed onto the stack.
// Stack: {
// Character '}' is encountered:

// It's a closing bracket.
// The stack is not empty, so we check if the top of the stack matches the expected opening bracket for '}', which is '{'. They match.
// The top of the stack is popped.
// Stack: ``
// After processing all characters in the input string, the stack is empty.
// Stack: ``

// Since the stack is empty at the end, the code returns true, indicating that the input string "()[]{}" contains balanced brackets.