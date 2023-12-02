#include <iostream>
#include <vector>
using namespace std;

int sumOfSquares(int num) {
    int sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }
    return sum;
}

bool isBeautiful(int num) {
    while (num != 1 && num != 4) {
        num = sumOfSquares(num);
    }
    return num == 1;
}

int countBeautifulNumbers(int l, int r) {
    int count = 0;
    for (int i = l; i <= r; ++i) {
        if (isBeautiful(i)) {
            count += i;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        int result = countBeautifulNumbers(l, r);
        cout << result << endl;
    }

    return 0;
}
