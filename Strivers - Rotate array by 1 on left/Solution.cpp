#include <iostream>
using namespace std;
void leftRotateArrayByOne(int arr[], int n)
{
	int temp = arr[0];
	for(int i = 0; i< n-1 ; i++)
	{
		arr[i] = arr[i+1];
	}
	arr[n-1] = temp;
}
void printArray(int arr[], int n)
{
	for(int i=0; i<n ; i++)
	{
		cout<<arr[i] << " ";
	}
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"\nOriginal array is : ";
	printArray(arr, n);
	
	leftRotateArrayByOne(arr, n);
	
	cout<<"\nThe left Rotated array is : ";
	printArray(arr, n);
	
	return 0;
}

===========================================================

JAVA 


import java.util.Arrays;

public class Main {
  
  public static void leftRotateArrayByOne(int[] arr, int n) {
    int temp = arr[0];
    for(int i = 0; i< n-1 ; i++) {
      arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
  }
  
  public static void printArray(int[] arr, int n) {
    for(int i=0; i<n ; i++) {
      System.out.print(arr[i] + " ");
    }
  }
  
  public static void main(String[] args) {
    int[] arr = {1,2,3,4,5,6,7,8,9,10};
    int n = arr.length;
    System.out.print("\nOriginal array is : ");
    printArray(arr, n);

    leftRotateArrayByOne(arr, n);

    System.out.print("\nThe left Rotated array is : ");
    printArray(arr, n);
  }
}