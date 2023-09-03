// NOT INITIALIZING I=0 CAN PUT YOU & ME IN BIG TROUBLE SO TAKE CARE !

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
class Solution
{
    public: 
        void sortColors(vector<int> &arr)
        {
            int i=0, low = 0, high = arr.size() - 1;
            while(i <= high)
            {
                if(arr[i] == 0) //taking care of 0's first to put in the beginning 
                {
                    swap(arr[i], arr[low]);
                    low ++;
                    i++;
                }
                else if(arr[i] == 2)    //taking care of 2's by putting them in end first
                {
                    swap(arr[i], arr[high]);
                    high --;
                }
                else{   //taking care of putting 1s in the middle
                    i++;
                }
            }
        }
};

int main()
{
    vector<int> arr1 = {0,1,1,0,2,1,0,0,1,2};
    Solution solution1;
    solution1.sortColors(arr1);
    cout<<"Output is: ";
    cout<<"[";
    for(int num : arr1)
    {
        cout<<num<<", ";
    }
    cout<<"]\n";
    return 0;
}