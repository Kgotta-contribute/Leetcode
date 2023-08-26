#include <iostream>
#include<climits>
using namespace std;

pair <int,int> findSecondSmallLarge(int arr[], int n)
{
	if(n<2)
	{
		return make_pair(INT_MIN, INT_MIN);
	}
	int smallest = min(arr[0], arr[1]);
	int secondsmallest = max(arr[0], arr[1]);
	int largest = secondsmallest;
	int secondlargest = smallest;
	
	for(int i=2; i<n; i++)
	{
		if(arr[i] < smallest)
		{
			secondsmallest = smallest;
			smallest = arr[i];
		}
		else if(arr[i] < secondsmallest)
		{
			secondsmallest = arr[i];
		}
		if(arr[i] > largest)
		{
			secondlargest = largest;
			largest = arr[i];
		}
		else if(arr[i] > secondlargest)
		{
			secondlargest = arr[i];
		}
	}
	return make_pair(secondsmallest, secondlargest);
}
int main()
{
	int n;
	cout<<"\nEnter number of elements in array : ";
	cin>>n;
	int arr[n];
	cout<<"\nEnter array elements: ";
	for(int i=0; i<n ; i++)
	{
		cout<<"\nEle : "<<i+1<<" : ";
		cin>>arr[i];
	}
	pair<int,int> result = findSecondSmallLarge(arr, n);
	
	cout<<"2nd Smallest is : "<<result.first<<endl;
	cout<<"2nd Largest is : "<<result.second<<endl;
	
	return 0;
}



// vector<int> getSecondOrderElements(int n, vector<int> a) 
// {
    
// }









