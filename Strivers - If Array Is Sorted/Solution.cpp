#include <iostream>
using namespace std;
//Check if the 2nd ele is greater than 1st ele -> this conditions satisfation shows we're on right track
bool isSorted(int arr[], int n)
{
	for(int i=1; i<n; i++)
	{
		if(arr[i] < arr[i-1])
		{
			return false;
		}
		return true;
	}
}
int main()
{
	int n=5,  arr[] = {1,2,3,4,5};
	cout <<  (isSorted(arr, n) ? "True" : "False") << endl;
}
