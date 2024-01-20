// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// class Solution {
// public:
//     string intToRoman(int num) {
//         vector<pair<int, string>> romanN = {
//             {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
//             {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
//             {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
//         };

//         string result = "";

//         for (const auto& pair : romanN) {
//             int v = pair.first;
//             string symbol = pair.second;

//             while (num >= v) {
//                 result += symbol;
//                 num -= v;
//             }
//         }

//         return result;
//     }
// };

// // int main() {
// //     Solution solution;
// //     int num;

// //     // Input a number
// //     cout << "Enter an integer (1-3999): ";
// //     cin >> num;

// //     if (num >= 1 && num <= 3999) {
// //         string roman = solution.intToRoman(num);
// //         cout << "Roman numeral: " << roman << endl;
// //     } else {
// //         cout << "Input is out of range." << endl;
// //     }

// //     return 0;
// // }




#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
   string intToRoman(int num) {
        // Arrays to store Roman numeral symbols and their corresponding values.
       string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

       string result = "";

        for (int i = 0; i < 13; i++) {
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    int num;

    // Input a number
    cout << "Enter an integer (1-3999): ";
    cin >> num;
    if (num >= 1 && num <= 3999) {
        string roman = solution.intToRoman(num);
        cout << "Roman numeral: " << roman << endl;
    } else {
        cout << "Input is out of range." <<endl;
    }

    return 0;
}



/////////////////////////// JAVA /////////////////////////////////



import java.util.Scanner;

public class Solution {
    public String intToRoman(int num) {
        // Arrays to store Roman numeral symbols and their corresponding values.
        String[] symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int[] values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        StringBuilder result = new StringBuilder();

        for (int i = 0; i < 13; i++) {
            while (num >= values[i]) {
                result.append(symbols[i]);
                num -= values[i];
            }
        }

        return result.toString();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter an integer (1-3999): ");
        int num = scanner.nextInt();

        if (num >= 1 && num <= 3999) {
            String roman = solution.intToRoman(num);
            System.out.println("Roman numeral: " + roman);
        } else {
            System.out.println("Input is out of range.");
        }
    }
}
