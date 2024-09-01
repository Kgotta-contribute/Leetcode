#include <iostream>
#include <vector>

using namespace std;

int subarrayWithMaxProduct(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) {
        return 0;
    }

    int max_product = arr[0];
    int min_product = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < 0) {
            swap(max_product, min_product);
        }

        max_product = max(arr[i], max_product * arr[i]);
        min_product = min(arr[i], min_product * arr[i]);

        result = max(result, max_product);
    }

    return result;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_product = maxProductSubarray(arr);
    cout << max_product << endl;

    return 0;
}
/*
Let's use the example array [2, 3, -2, 4].

Initialization:

max_product = 2
min_product = 2
result = 2
Processing the array:

Element 3:

No negative number swap needed.
max_product = max(3, 2 * 3) = max(3, 6) = 6
min_product = min(3, 2 * 3) = min(3, 6) = 3
result = max(2, 6) = 6
Element -2:

Swap max_product and min_product.
After swap: max_product = 3, min_product = 6
max_product = max(-2, 3 * -2) = max(-2, -6) = -2
min_product = min(-2, 6 * -2) = min(-2, -12) = -12
result = max(6, -2) = 6
Element 4:

No negative number swap needed.
max_product = max(4, -2 * 4) = max(4, -8) = 4
min_product = min(4, -12 * 4) = min(4, -48) = -48
result = max(6, 4) = 6
Final Result:

result = 6
*/



// JAVA

import java.util.Scanner;

public class MaxProductSubarray {

    public static int subarrayWithMaxProduct(int[] arr) {
        int n = arr.length;
        if (n == 0) {
            return 0;
        }

        int maxProduct = arr[0];
        int minProduct = arr[0];
        int result = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] < 0) {
                // Swap maxProduct and minProduct
                int temp = maxProduct;
                maxProduct = minProduct;
                minProduct = temp;
            }

            maxProduct = Math.max(arr[i], maxProduct * arr[i]);
            minProduct = Math.min(arr[i], minProduct * arr[i]);

            result = Math.max(result, maxProduct);
        }

        return result;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        int maxProduct = subarrayWithMaxProduct(arr);
        System.out.println(maxProduct);

        scanner.close();
    }
}







// PYTHON 

def subarray_with_max_product(arr):
    if not arr:
        return 0

    max_product = arr[0]
    min_product = arr[0]
    result = arr[0]

    for i in range(1, len(arr)):
        if arr[i] < 0:
            max_product, min_product = min_product, max_product

        max_product = max(arr[i], max_product * arr[i])
        min_product = min(arr[i], min_product * arr[i])

        result = max(result, max_product)

    return result

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    arr = list(map(int, data[1:]))

    max_product = subarray_with_max_product(arr)
    print(max_product)

if __name__ == "__main__":
    main()
