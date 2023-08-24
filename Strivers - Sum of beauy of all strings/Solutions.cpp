#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int sumOfBeauty(string s) {
    int n = s.length();
    int result = 0;
    
    for (int i = 0; i < n; i++) {
        unordered_map<char, int> freq;
        int mostFreq = 0, leastFreq = n;
        
        for (int j = i; j < n; j++) {
            freq[s[j]]++;
            mostFreq = max(mostFreq, freq[s[j]]);
            leastFreq = min(leastFreq, freq[s[j]]);
            
            result += (mostFreq - leastFreq);
        }
    }
    
    return result;
}

int main() {
    string s1 = "aabcb";
    cout << "Sum of beauty of all substrings: " << sumOfBeauty(s1) << endl;
    
    string s2 = "aabcbaa";
    cout << "Sum of beauty of all substrings: " << sumOfBeauty(s2) << endl;
    
    return 0;
}
