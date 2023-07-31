#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

string reverseWords(string s) 
{
    stringstream ss(s);
    string word, reversedString;
    while (ss >> word) 
    {
        reversedString = word + " " + reversedString;
    }
    reversedString.pop_back(); // Remove the extra space at the end
    return reversedString;
}

int main() 
{
    string inputString;
    cout << "Enter a string: ";
    getline(cin, inputString);

    string reversedString = reverseWords(inputString);
    cout << "Output: " << reversedString << endl;

    return 0;
}