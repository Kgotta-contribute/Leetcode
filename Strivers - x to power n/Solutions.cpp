
// JAVA

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the value of x: ");
        double x = scanner.nextDouble();
        System.out.print("Enter the value of n: ");
        int n = scanner.nextInt();

        double result = power(x, n);

        System.out.printf("Result: %.6f%n", result);
    }

    public static double power(double x, int n) {
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
}







#include <iostream>
#include <iomanip> // For setting decimal precision

using namespace std;

double myPow(double x, int n) {
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

    double result = myPow(x, n);

    cout << fixed << setprecision(6);
    cout << "Result: " << result << endl;

    return 0;
}






// PYTHON

class Solution:
    def myPow(self, x: float, n: int) -> float: 
        # Edge case: n is zero
        if n == 0:
            return 1.0
        
        # Handle negative exponents
        if n < 0:
            x = 1 / x
            n = -n
        
        result = 1.0
        # Fast exponentiation
        while n > 0:
            if n % 2 == 1:  # If n is odd
                result *= x
            x *= x  # Square the base
            n //= 2  # Reduce n by half
        
        return result

def main():
    x = float(input("Enter the value of x: "))
    n = int(input("Enter the value of n: "))

    result = myPow(x, n)

    print(f"Result: {result:.6f}")

if __name__ == "__main__":
    main()
