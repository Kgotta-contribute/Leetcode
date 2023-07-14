#include <iostream>
#include<vector>
using namespace std;

vector<int> moveZeroes(int n , vector<int> a)
{
	int j = -1;
	
	for(int i=0; i<n ; i++)
	{
		if(a[i] == 0)
		{
			j=i;
			break;
		}
	}
	
	if(j == -1) return a;	//Indicates no non zero elements
	
	for(int i=j+1; i<n; i++)
	{
		if( a[i] != 0 )
		{
			swap(a[j], a[i]);
			j++;
		}
	}
	return a;
}
int main()
{
	vector<int> arr = {7,6,5,4,0,0,1,3,0,7};			//int n = 10;//sizeof(arr)/sizeof(arr[0]);
	int n = arr.size();

	vector<int> ans = moveZeroes(n , arr);
	
	for(auto &it : ans)
	{
		cout<<it<<" ";
	}
	cout<<endl;
	
	return 0;
}
