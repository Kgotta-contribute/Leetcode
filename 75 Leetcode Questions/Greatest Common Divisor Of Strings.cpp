// QUESTION -> https://leetcode.com/problems/greatest-common-divisor-of-strings/description/?envType=study-plan-v2&envId=leetcode-75


// PYTHON
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:        
            return ""
        gcdLength = gcd(len(str1), len(str2))
        return str1[:gcdLength]





        

// JAVA
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        
        // Step 1: If no common divisor exists, return ""
        if (!(str1 + str2).equals(str2 + str1)) {
            return "";
        }

        // Step 2: GCD of lengths = length of the answer
        int gcdLength = gcd(str1.length(), str2.length());

        // Step 3: Return the prefix of that length
        return str1.substring(0, gcdLength);
    }

    // Euclidean GCD helper
    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}