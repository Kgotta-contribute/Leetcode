
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() 
{
    int a[] = {1,2,3,4};
    
    next_permutation(a,a+3);
    
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3];
    
    return 0;
}
