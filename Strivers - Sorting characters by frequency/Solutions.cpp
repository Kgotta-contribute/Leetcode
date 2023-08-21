#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

bool cmp(const std::pair<char, int>& a, const std::pair<char, int>& b) 
{
    return a.second > b.second;
}
// return a.second > b.second;: This is the comparison logic. The function compares 
// the second element (the frequency) of the two pairs a and b. It returns true if 
// the frequency of a is greater than the frequency of b, indicating that a should 
// come before b in the sorted order.

std::string freqSort(std::string s) {
    std::unordered_map<char, int> charFreq;
    for (char c : s) {
        charFreq[c]++;
    }

    std::vector<std::pair<char, int>> charFreqPairs;
    for (const auto& entry : charFreq) {
        charFreqPairs.push_back(entry);
    }

    std::sort(charFreqPairs.begin(), charFreqPairs.end(), cmp);

    std::string result;
    for (const auto& pair : charFreqPairs) {
        result += std::string(pair.second, pair.first);
    }

    return result;
}

int main() {
    std::string input1 = "abcAbc";
    std::string sortedString1 = freqSort(input1);
    std::cout << "Sample Input 1: " << input1 << std::endl;
    std::cout << "Sorted string by character frequency: " << sortedString1 << std::endl;

    std::string input2 = "tree";
    std::string sortedString2 = freqSort(input2);
    std::cout << "Sample Input 2: " << input2 << std::endl;
    std::cout << "Sorted string by character frequency: " << sortedString2 << std::endl;

    std::string input3 = "cccaaa";
    std::string sortedString3 = freqSort(input3);
    std::cout << "Sample Input 3: " << input3 << std::endl;
    std::cout << "Sorted string by character frequency: " << sortedString3 << std::endl;

    std::string input4 = "Aabb";
    std::string sortedString4 = freqSort(input4);
    std::cout << "Sample Input 4: " << input4 << std::endl;
    std::cout << "Sorted string by character frequency: " << sortedString4 << std::endl;

    return 0;
}






// Sample Input 1: "abcAbc"

// Character frequency map:
// 'a': 2
// 'b': 2
// 'c': 2
// 'A': 1
// Vector of pairs:
// ('a', 2)
// ('b', 2)
// ('c', 2)
// ('A', 1)
// Sorted vector of pairs (based on frequency):
// ('a', 2)
// ('b', 2)
// ('c', 2)
// ('A', 1)
// Resulting sorted string:
// "aabbccA"
// Output:
// Sample Input 1: abcAbc
// Sorted string by character frequency: aabbccA
// Sample Input 2: "tree"

// Character frequency map:
// 't': 1
// 'r': 1
// 'e': 2
// Vector of pairs:
// ('t', 1)
// ('r', 1)
// ('e', 2)
// Sorted vector of pairs (based on frequency):
// ('e', 2)
// ('t', 1)
// ('r', 1)
// Resulting sorted string:
// "eetr"
// Output:
// Sample Input 2: tree
// Sorted string by character frequency: eetr
// Sample Input 3: "cccaaa"

// Character frequency map:
// 'c': 3
// 'a': 3
// Vector of pairs:
// ('c', 3)
// ('a', 3)
// Sorted vector of pairs (based on frequency):
// ('c', 3)
// ('a', 3)
// Resulting sorted string:
// "cccAAA"
// Output:
// Sample Input 3: cccaaa
// Sorted string by character frequency: cccAAA
// Sample Input 4: "Aabb"

// Character frequency map:
// 'A': 1
// 'a': 1
// 'b': 2
// Vector of pairs:
// ('A', 1)
// ('a', 1)
// ('b', 2)
// Sorted vector of pairs (based on frequency):
// ('b', 2)
// ('A', 1)
// ('a', 1)
// Resulting sorted string:
// "bbaA"
// Output:
// Sample Input 4: Aabb
// Sorted string by character frequency: bbaA