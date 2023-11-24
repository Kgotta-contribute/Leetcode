#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x, int n) 
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x) 
        {
            ans = mid;
            high = mid - 1;
        }
        else 
        {
            low = mid + 1; 
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 5, 8, 9, 15, 19};
    int n = 6, x = 9;
    int ind = upperBound(arr, x, n);
    cout << "The upper bound is the index: " << ind << "\n";
    return 0;
}





// JAVA

import java.util.*;

public class Main {
    public static int upperBound(List<Integer> arr, int x, int n) {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr.get(mid) > x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        List<Integer> arr = Arrays.asList(3, 5, 8, 9, 15, 19);
        int n = 6, x = 9;
        int ind = upperBound(arr, x, n);
        System.out.println("The upper bound is the index: " + ind);
    }
}
