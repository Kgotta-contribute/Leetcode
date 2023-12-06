#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        // Iterate while the left pointer is less than the right pointer.
        while (left < right) 
        {
            // Move the left pointer to the right until it points to an alphanumeric character.
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Move the right pointer to the left until it points to an alphanumeric character.
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Compare characters at the left and right positions while ignoring case.
            if (tolower(s[left]) != tolower(s[right])) {
                return false; // If they don't match, it's not a palindrome.
            }
            
            left++;  // Move the left pointer to the right.
            right--; // Move the right pointer to the left.
        }
        return true; // If the loop completes without mismatches, it's a palindrome.
    }
};

int main() {
    Solution solution;
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = " ";

    cout << boolalpha;  // Print bool values as "true" or "false".
    cout << solution.isPalindrome(s1) << endl;  // Output: true
    cout << solution.isPalindrome(s2) << endl;  // Output: false
    cout << solution.isPalindrome(s3) << endl;  // Output: true

    return 0;
}



// Example 1: s1 = "A man, a plan, a canal: Panama"

// Iteration 1:

// left = 0, right = 19 (string length minus 1)
// left moves to the first alphanumeric character ('A').
// right moves to the last alphanumeric character ('a').
// Iteration 2:

// left = 1, right = 18
// left moves to 'm'.
// right moves to 'a'.
// Iteration 3:

// left = 3, right = 17
// left moves to 'a'.
// right moves to 'l'.
// ... (continue iterations until they meet in the middle)

// Iteration 10:

// left = 7, right = 13
// left moves to 'n'.
// right moves to 'n'.
// Iteration 11:

// left = 9, right = 11
// left moves to 'a'.
// right moves to 'a'.
// The loop ends because left is no longer less than right.

// The code returns true because all characters matched, and it's a palindrome.

// Example 2: s2 = "race a car"

// Iteration 1:

// left = 0, right = 8
// left moves to 'r'.
// right moves to 'r'.
// Iteration 2:

// left = 1, right = 7
// left moves to 'a'.
// right moves to 'a'.
// Iteration 3:

// left = 5, right = 5
// left moves to 'a'.
// right moves to 'a'.
// The loop ends because left is no longer less than right.

// The code returns false because not all characters matched, and it's not a palindrome.

// Example 3: s3 = " "

// In this case, there are no non-alphanumeric characters, so left and right start at 0.

// Iteration 1:

// left = 0, right = 0
// left and right point to the same character, which is alphanumeric.






// JAVA

public class Solution {
    public boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length() - 1;

        // Iterate while the left pointer is less than the right pointer.
        while (left < right) {
            // Move the left pointer to the right until it points to an alphanumeric character.
            while (left < right && !Character.isLetterOrDigit(s.charAt(left))) {
                left++;
            }
            // Move the right pointer to the left until it points to an alphanumeric character.
            while (left < right && !Character.isLetterOrDigit(s.charAt(right))) {
                right--;
            }

            // Compare characters at the left and right positions while ignoring case.
            if (Character.toLowerCase(s.charAt(left)) != Character.toLowerCase(s.charAt(right))) {
                return false; // If they don't match, it's not a palindrome.
            }

            left++;  // Move the left pointer to the right.
            right--; // Move the right pointer to the left.
        }

        return true; // If the loop completes without mismatches, it's a palindrome.
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s1 = "A man, a plan, a canal: Panama";
        String s2 = "race a car";
        String s3 = " ";

        System.out.println(solution.isPalindrome(s1));  // Output: true
        System.out.println(solution.isPalindrome(s2));  // Output: false
        System.out.println(solution.isPalindrome(s3));  // Output: true
    }
}
