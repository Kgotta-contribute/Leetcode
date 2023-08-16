#include <iostream>
#include <string>

using namespace std;

string largestOddNumber(string num) {
    int n = num.size();
    for (int i = n - 1; i >= 0; i--) {
        if ((num[i] - '0') % 2 == 1) {
            return num.substr(0, i + 1);
        }
    }
    return "";
}

int main() {
    string num1 = "52";
    cout << "Input: " << num1 << " Output: " << largestOddNumber(num1) << endl;

    string num2 = "4206";
    cout << "Input: " << num2 << " Output: " << largestOddNumber(num2) << endl;

    string num3 = "35427";
    cout << "Input: " << num3 << " Output: " << largestOddNumber(num3) << endl;

    return 0;
}
