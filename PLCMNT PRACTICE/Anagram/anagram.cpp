//Two strings are anagram or not
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool isAnagram(string inp1, string inp2)
{
    if(inp1.length() != inp2.length())
    {
        return false;
    }
    sort( inp1.begin() , inp1.end());
    sort( inp2.begin() , inp2.end());

    return inp1 == inp2;
}
int main()
{
    string inp1, inp2;

    cout<<"\nEnter two strings: ";
    cin >> inp1>>inp2;

    if(isAnagram(inp1, inp2))
    {
        cout<<inp1<<" & "<<inp2<<" are anagrams!"<<endl;
    }
    else
    {
        cout<<inp1<<" & "<<inp2<<" are not anagrams!"<<endl;
    }

    return 0;
}