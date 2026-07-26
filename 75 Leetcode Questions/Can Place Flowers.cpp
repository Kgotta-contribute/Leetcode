// QUESTION - https://leetcode.com/problems/can-place-flowers/description/?envType=study-plan-v2&envId=leetcode-75

// PYTHON 
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        if n == 0:
            return True

        m = len(flowerbed)

        for i in range(m):
            if (
                flowerbed[i] == 0 and
                (i == 0 or flowerbed[i - 1] == 0) and
                (i == m - 1 or flowerbed[i + 1] == 0)
            ):
                flowerbed[i] = 1
                n -= 1
                if n == 0:
                    return True

        return False






// JAVA
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {

        for (int i = 0; i < flowerbed.length && n > 0; i++) {

            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i - 1] == 0) &&
                (i == flowerbed.length - 1 || flowerbed[i + 1] == 0)) {

                flowerbed[i] = 1;
                n--;
            }
        }

        return n == 0;
    }
}
