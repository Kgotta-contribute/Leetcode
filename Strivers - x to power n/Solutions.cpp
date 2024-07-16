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





// PYTHON

def power(x, n):
    if n == 0:
        return 1.0
    if n < 0:
        x = 1 / x
        n = -n
    result = 1.0
    for _ in range(n):
        result *= x
    return result

def main():
    x = float(input("Enter the value of x: "))
    n = int(input("Enter the value of n: "))

    result = power(x, n)

    print(f"Result: {result:.6f}")

if __name__ == "__main__":
    main()





/*
class Solution {
public:
    double myPow(double x, int n) {
        
        if(n < 0) {
            x = 1 / x;
        } 
        
        long num = labs(n);
        
        double pow = 1;
        
        while(num){ // equivalent to while(num != 0)
            if(num & 1) { // equivalent to if((num & 1) != 0)
                pow *= x;
            }
            
            x *= x;
            num >>= 1;
        }
        
        return pow;
    }
};
*/