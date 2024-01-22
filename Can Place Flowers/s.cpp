#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int len = flowerbed.size();
        
        for (int i = 0; i < len; ++i) {
            if (flowerbed[i] == 0) {
                // Check the conditions for planting a flower
                bool prevEmpty = (i == 0) || (i > 0 && flowerbed[i - 1] == 0);
                bool nextEmpty = (i == len - 1) || (i < len - 1 && flowerbed[i + 1] == 0);
                
                if (prevEmpty && nextEmpty) {
                    flowerbed[i] = 1;  // Plant a flower
                    ++cnt;
                }
            }
        }
        
        return cnt >= n;
    }
};