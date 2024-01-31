#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size(), lastWordLength = 0, countingStarted = 0;
        for (int i = size - 1; i >= 0; i--) 
        {
            if (s[i] == ' ' && countingStarted)
                break;
            if (s[i] != ' ') {
                countingStarted = 1;
                lastWordLength++;
            }
        }
        return lastWordLength;
    }
};


// #include <string>
// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         int length = 0;
//         int i = s.size() - 1;

//         // Skip trailing spaces
//         while (i >= 0 && s[i] == ' ') {
//             i--;
//         }

//         // Count the length of the last word
//         while (i >= 0 && s[i] != ' ') {
//             length++;
//             i--;
//         }

//         return length;
//     }
// };



/*
s = "Hello World"
size = 11: The length of the input string.
lastWordLength = 0: 
countingStarted = 0: Flag to indicate whether counting has started.

Iterates through the string in reverse, starting from the last character.

if (s[i] == ' ' && countingStarted) break;: Checks if the current character is a space and if counting has already started. If true, it breaks out of the loop, as trailing spaces are not counted.

if (s[i] != ' ') { countingStarted = 1; lastWordLength++; }: If the current character is not a space, it indicates a non-space character.
If counting has not started (countingStarted is 0), set countingStarted to 1, indicating that counting has started.
Increment lastWordLength to count the length of the last word.

Iteration starts from the last character 'd':
s[i] != ' ': Increment lastWordLength to 1, set countingStarted to 1.
Iteration continues to 'l':
s[i] != ' ': Increment lastWordLength to 2......
The function returns 5, which is the length of the last word "World"
*/