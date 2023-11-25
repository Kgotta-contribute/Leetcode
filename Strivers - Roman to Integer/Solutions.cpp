#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int nums[s.length()];

        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case 'M':
                    nums[i] = 1000;
                    break;
                case 'D':
                    nums[i] = 500;
                    break;
                case 'C':
                    nums[i] = 100;
                    break;
                case 'L':
                    nums[i] = 50;
                    break;
                case 'X':
                    nums[i] = 10;
                    break;
                case 'V':
                    nums[i] = 5;
                    break;
                case 'I':
                    nums[i] = 1;
                    break;
            }
        }
        int sum = 0;
        // MIX = 1000,   1,    10
        for (int i = 0; i < s.length() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                sum -= nums[i];
            } else {
                sum += nums[i];
            }
        }
        return sum + nums[s.length() - 1];
    }
};

int main() {
    Solution solution;
    string s;

    // Input a Roman numeral
    cout << "Enter a Roman numeral: ";
    cin >> s;

    int result = solution.romanToInt(s);
    cout << "Integer value: " << result << endl;

    return 0;
}




===============================================================================================






// JAVA CODE : - 

import java.util.Scanner;

class Solution {
    public int romanToInt(String s) {
        int nums[] = new int[s.length()];

        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case 'M':
                    nums[i] = 1000;
                    break;
                case 'D':
                    nums[i] = 500;
                    break;
                case 'C':
                    nums[i] = 100;
                    break;
                case 'L':
                    nums[i] = 50;
                    break;
                case 'X':
                    nums[i] = 10;
                    break;
                case 'V':
                    nums[i] = 5;
                    break;
                case 'I':
                    nums[i] = 1;
                    break;
            }
        }

        int sum = 0;

        for (int i = 0; i < s.length() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                sum -= nums[i];
            } else {
                sum += nums[i];
            }
        }

        return sum + nums[s.length() - 1];
    }
}

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a Roman numeral: ");
        String s = scanner.next();

        int result = solution.romanToInt(s);
        System.out.println("Integer value: " + result);
    }
}
