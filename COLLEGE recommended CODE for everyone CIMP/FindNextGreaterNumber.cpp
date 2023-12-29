#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string findNextGreaterNumber(string num)
{
    int n = num.size(), i;      // n = 6, num = 208765
    for(i = n-2; i>=0; i--)     //  i=4, 3,  2, 1
    {
        if(num[i] < num[i+1])   // 6 < 5,    7<6 ,    8<7,     0<8
        {
            break;
        }
    }
    if(i == -1)
    {
        return "Not Possible";
    }
    int j;                      //  num = 208765
    for(j = n-1; j>i; j--)      //  j = 5 => (n-1), num[5] > num[1] (5 > 0)
    {
        if(num[j] > num[i])
        {
            break;
        }
    }
    swap(num[i], num[j]);       // swap num[1] & num[5]   258760
    reverse(num.begin() + i + 1, num.end()); // reverse from index 2 to n  ( ie. reverse this 8760 ) to get 250678
    return num;
}
int main()
{
    string n;
    cout<<"\nEnter the number: ";
    cin >> n;
    string result = findNextGreaterNumber(n);
    cout<< " Output: "<<result<<endl;
    return 0;
}


