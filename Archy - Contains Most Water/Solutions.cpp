class Solution
{
    public int maxArea(int height[])
    {
        int n = height.length;  // returns height of the array
        int left = 0, right = n-1 ;
        int maxArea = 0;
        while(left<right)
        {
            int area = Math.min(height[left], height[right])*(right-left);
            maxArea = Math.max(maxArea, area);
            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxArea;
    }
}

/*
Iterations: 
-> left=0, right=8
-> left=1, right=8
-> left=1, right=7
.....etc                ie. left & right just scores the index

    left=0 and right=8. We calculate the area as Math.min(height[0], height[8])*(8-0) = Math.min(1, 7) * 8 = 8. Since 8 is greater than the current maxArea of 0, we set maxArea=8.
    left=1 and right=8. We calculate the area as Math.min(height[1], height[8])*(8-1) = Math.min(8, 7) * 7 = 49. Since 49 is greater than the current maxArea of 8, we set maxArea=49.
    left=1 and right=7. We calculate the area as Math.min(height[1], height[7])*(7-1) = Math.min(8, 3) * 6 = 18. Since 49 is still the current maxArea, we don't update it.
    left=1 and right=6. We calculate the area as Math.min(height[1], height[6])*(6-1) = Math.min(8, 8) * 5 = 40. Since 49 is still the current maxArea, we don't update it.
    left=1 and right=5. We calculate the area as Math.min(height[1], height[5])*(5-1) = Math.min(8, 4) * 4 = 32. Since 49 is still the current maxArea, we don't update it.
    left=2 and right=5. We calculate the area as Math.min(height[2], height[5])*(5-2) = Math.min(6, 4) * 3 = 12. Since 49 is still the current maxArea, we don't update it.
    left=2 and right=4. We calculate the area as Math.min(height[2], height[4])*(4-2) = Math.min(6, 5) * 2 = 10. Since 49 is still the current maxArea, we don't update it.
    left=3 and right=4. We calculate the area as Math.min(height[3], height[4])*(4-3) = Math.min(2, 5) * 1 = 2. Since 49 is still the current maxArea, we don't update it.

*/