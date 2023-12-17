#include<bits/stdc++.h>
using namespace std;

void rearrange(arr, n)
{
    int j=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] < 0)
        {
            if( i!= j)
                swap(arr[i], arr[j])
            j++;
        }
    }
}

// int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };