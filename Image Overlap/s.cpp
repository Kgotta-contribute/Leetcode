// lil complex

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int result = 0;

        for (int x = -n + 1; x < n; x++) {
            for (int y = -n + 1; y < n; y++) {
                int overlap = 0;

                for (int i = max(0, x); i < min(n, n + x); i++) {
                    for (int j = max(0, y); j < min(n, n + y); j++) {
                        overlap += img1[i][j] & img2[i - x][j - y];
                    }
                }

                result = max(result, overlap);
            }
        }

        return result;
    }
};
