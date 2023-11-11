#include <iostream>
#include <iomanip> // For setting decimal precision

using namespace std;

double power(double x, int n) {
    if (n == 0) {
        return 1.0;
    }
    if (n < 0) {
        x = 1 / x;
        n = -n;
    }
    double result = 1.0;
    for (int i = 0; i < n; ++i) {
        result *= x;
    }
    return result;
}

int main() {
    double x;
    int n;
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the value of n: ";
    cin >> n;

    double result = power(x, n);

    cout << fixed << setprecision(6);
    cout << "Result: " << result << endl;

    return 0;
}
