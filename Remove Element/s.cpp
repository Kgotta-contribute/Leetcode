#include <vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;  // Variable to keep track of the count of elements not equal to val
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                if (i != k) {
                    nums[k] = nums[i];
                }
                k++;
            }
        }
        
        return k;
    }
};
// hum bhi dariyan hai 
// hume apna hoonar maloom hai
// jis taraf bhi chal padenge 
// raasta ho jaayega

// jab bhi accha samay ho & bura samay ho
// ye waqt guzar jaayega - yaad rakhna & aage badhna

// tanav jhelne ke liye apne aap ko fool proof & touugh shield bana lena
// kyu darein life mein kya hoga agar kuch nahi hoga toh tazurba hoga