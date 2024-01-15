#include<bits/stdc++.h>
using namespace std;

int findFloor(int arr[], int n, int x)
{
    int low = 0, high = n-1, ans = -1;

    while(low <= high)  // int arr[] = {3,4,4,7,8,10};       int n = 6, x= 5;
    {
        int mid = (low + high) / 2;

        if(arr[mid] <= x)
        {
            ans = arr[mid];
            //look for smaller index on right
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int findCeil(int arr[], int n, int x)
{
    int low = 0, high = n-1, ans = -1;

    while(low <= high)      // int arr[] = {3,4,4,7,8,10};       int n = 6, x= 5;
    {
        int mid = (low + high) / 2;

        if(arr[mid] >= x)
        {
            ans = arr[mid];
            //look for larger index on left
            high = mid - 1;
        }
        else
        {
            low = mid+1;
        }
    }
    return ans;
}
pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    int f = findFloor(arr, n, x);
    int c = findCeil(arr, n, x);
    return make_pair(f,c);
}
int main()
{
    int arr[] = {3,4,4,7,8,10};
    int n = 6, x= 5;
    pair<int, int> ans = getFloorAndCeil(arr, n, x);
    cout<<"The floor & Ceil are: "<<ans.first<<" & "<<ans.second<<endl;
    return 0;
}









// java

import java.util.Arrays;

public class FloorCeilFinder {

    public static int findFloor(int[] arr, int n, int x) {
        int low = 0, high = n - 1, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= x) {
                ans = arr[mid];
                // look for smaller index on right
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    public static int findCeil(int[] arr, int n, int x) {
        int low = 0, high = n - 1, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= x) {
                ans = arr[mid];
                // look for larger index on left
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    public static int[] getFloorAndCeil(int[] arr, int n, int x) {
        int f = findFloor(arr, n, x);
        int c = findCeil(arr, n, x);
        return new int[]{f, c};
    }

    public static void main(String[] args) {
        int[] arr = {3, 4, 4, 7, 8, 10};
        int n = arr.length;
        int x = 5;
        int[] ans = getFloorAndCeil(arr, n, x);
        System.out.println("The floor & Ceil are: " + ans[0] + " & " + ans[1]);
    }
}










