#include<iostream>
using namespace std;

int search(int arr[],int n, int num_to_find)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i]== num_to_find)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1,2,5,4,6,8,700};
    int n = sizeof(arr)/sizeof(arr[0]);
    int num_to_find = 5;
    int res = search(arr, n, num_to_find);
    cout<<"num_to_find :" << num_to_find<< ", is present at index ->"<<res<<endl;
}