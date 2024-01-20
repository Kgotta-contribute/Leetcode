#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) 
    {
        int len = s.length();
        char* stack = new char[len];
        int top = 0;
        for (char c : s) 
        {
            if (c == '(' || c == '[' || c == '{') 
            {
                //  it first assigns the value of c to stack[top] and then increments the value of top
                stack[top++] = c;
            } 
            else if (c == ')' || c == ']' || c == '}') 
            {
                //This line is checking whether the current closing parenthesis c matches the corresponding 
                //opening parenthesis at the top of the stack. The --top part decrements the value of top before using it as an index to access the top element of the stack.
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

    bool isValidPair(char open, char close) 
    {
        return (open == '(' && close == ')') ||
               (open == '[' && close == ']') ||
               (open == '{' && close == '}');
    }
};

int main() {
    Solution solution;
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(([][]))]}";

    cout << solution.isValid(s1) << endl;  // Output: 1 (True)
    cout << solution.isValid(s2) << endl;  // Output: 1 (True)
    cout << solution.isValid(s3) << endl;  // Output: 0 (False)

    return 0;
}




// JAVA

public class Solution {
    public boolean isValid(String s) {
        int len = s.length();
        char[] stack = new char[len];
        int top = 0;
        for (char c : s.toCharArray()) 
        {
            if (c == '(' || c == '[' || c == '{') 
            {
                stack[top++] = c;
            } 
            else if (c == ')' || c == ']' || c == '}') 
            {
                if (top == 0 || !isValidPair(stack[--top], c)) 
                {
                    return false;
                }
            }
        }
        return top == 0;
    }
    private boolean isValidPair(char open, char close) 
    {
        return (open == '(' && close == ')') ||
               (open == '[' && close == ']') ||
               (open == '{' && close == '}');
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        String s1 = "()";
        String s2 = "()[]{}";
        String s3 = "(]";

        System.out.println(s.isValid(s1));  // Output: true
        System.out.println(s.isValid(s2));  // Output: true
        System.out.println(s.isValid(s3));  // Output: false
    }
}
