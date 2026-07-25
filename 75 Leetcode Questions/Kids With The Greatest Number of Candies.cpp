// QUESTION -> https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/?envType=study-plan-v2&envId=leetcode-75


// PYTHON 
class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        max_candies = max(candies)
        return [c + extraCandies >= max_candies for c in candies]




        THE ANATOMY 

[  c + extraCandies >= max_candies   for c in candies  ]
   |__________________________|       |______________|
          EXPRESSION                    ITERATOR
   "what to put in the list"        "loop over this"


It is equal to : 
result = []
for c in candies:
    result.append(c + extraCandies >= max_candies)
return result




// JAVA 
class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int max = 0;
        for (int c : candies) if (c > max) max = c;
        
        List<Boolean> result = new ArrayList<>(candies.length);
        for (int c : candies) result.add(c + extraCandies >= max);
        
        return result;
    }
}
