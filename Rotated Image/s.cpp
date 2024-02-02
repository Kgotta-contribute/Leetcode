#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for (int i = 0; i < n; ++i) {
            int start = 0, end = n - 1;
            while (start < end) {
                swap(matrix[i][start], matrix[i][end]);
                ++start;
                --end;
            }
        }
    }
};


/*
first take transpose then take reverse :
in transpose we swap 0,1 & 1,0; 0,2 & 2,0; 1,2 & 2,1
in reverse we do -> swap of 0,0 & 0,2 ; 1,0 & 1,2 ; 2,0 & 2,2

0,0	0,1	0,2
 7   4   1

1,0	1,1	1,2
 8   5   2

2,0	2,1	2,2
 9   6   3

*/