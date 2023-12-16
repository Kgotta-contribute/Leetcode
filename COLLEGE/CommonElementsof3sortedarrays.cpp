#include<iostream>
using namespace std;

void findInter(int a1[], int a2[], int temp[], int m, int n, int k)
{
    int i=0, j=0;
    while(i<m && j<n)
    {
        if(a1[i] < a2[j])
        {
            i++;
        }
        else if(a2[j] < a1[i])
        {
            j++;
        }
        else
        {
            temp[k] = a1[i];
            i++;
            j++;
            k++;
        }
    }
}