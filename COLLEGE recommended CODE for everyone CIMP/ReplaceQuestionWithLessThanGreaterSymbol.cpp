/*
"Write a function in C++ that takes a string containing characters '.', '*', and '?' as input. The function 
should replace each '?' character with 'a' and then find the length of the longest symmetric substring in 
the modified string. Finally, the function should return the length of the longest symmetric substring plus 
the count of '?' characters in the original string. Additionally, provide a sample test case to demonstrate 
the function's usage."
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solution(string &S) {
    string replacedS = S;
    int numQM = count(S.begin(), S.end(), '?');

    for (char &c : replacedS) {
        if (c == '?') {
            c = 'a'; // Replace '?' with 'a' for now
        }
    }

    int maxSymmetricLength = 0;
    int n = replacedS.length();

    for (int i = 0; i < n; i++) {
        int left = i;
        int right = i + 1;

        while (left >= 0 && right < n && (replacedS[left] == replacedS[right] || replacedS[left] == 'a' || replacedS[right] == 'a')) {
            if (replacedS[left] != 'a' && replacedS[right] != 'a') {
                maxSymmetricLength = max(maxSymmetricLength, right - left + 1);
            }
            left--;
            right++;
        }
    }

    return maxSymmetricLength + numQM;
}

int main() {
    string S = "a?b?c?d?e";
    cout << solution(S) << endl;

    return 0;
}
