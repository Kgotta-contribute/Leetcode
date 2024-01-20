// 19 DECEMBER 2023

#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int countAsterisks(const vector<string>& strVector) {
    int totalCount = 0;
    for (const auto& str : strVector) { //It is used to iterate over the elements of a container, in this case, a vector of strings called strVector
        for (char c : str) {
            if (c == '*') {
                totalCount++;
                break; // Break after finding one asterisk in the string
            }
        }
    }
    return totalCount;
}

int main() {
    vector<string> strVector = {
        ".*#..*",
        ".*#*.#",
        "######",
        ".*..#.",
        "...###"
    };
    int asteriskCount = countAsterisks(strVector);
    cout << "Total asterisks found: " << asteriskCount << endl;
    return 0;
}
