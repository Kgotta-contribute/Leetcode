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
