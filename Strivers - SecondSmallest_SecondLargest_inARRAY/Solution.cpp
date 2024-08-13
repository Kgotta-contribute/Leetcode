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



// JAVA

import java.util.Scanner;

public class SecondSmallestLargest {

    public static int[] findSecondSmallLarge(int[] arr) {
        if (arr.length < 2) {
            return new int[]{Integer.MIN_VALUE, Integer.MIN_VALUE};
        }
        
        int smallest = Math.min(arr[0], arr[1]);
        int secondSmallest = Math.max(arr[0], arr[1]);
        int largest = secondSmallest;
        int secondLargest = smallest;

        for (int i = 2; i < arr.length; i++) {
            if (arr[i] < smallest) {
                secondSmallest = smallest;
                smallest = arr[i];
            } else if (arr[i] < secondSmallest) {
                secondSmallest = arr[i];
            }
            if (arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            } else if (arr[i] > secondLargest) {
                secondLargest = arr[i];
            }
        }

        return new int[]{secondSmallest, secondLargest};
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter number of elements in array: ");
        int n = scanner.nextInt();
        
        if (n < 2) {
            System.out.println("Array must have at least 2 elements.");
            return;
        }
        
        int[] arr = new int[n];
        
        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            System.out.print("Ele " + (i + 1) + ": ");
            arr[i] = scanner.nextInt();
        }
        
        int[] result = findSecondSmallLarge(arr);
        
        System.out.println("2nd Smallest is: " + result[0]);
        System.out.println("2nd Largest is: " + result[1]);
        
        scanner.close();
    }
}





// PYTHON

def find_second_small_large(arr):
    if len(arr) < 2:
        return (float('-inf'), float('-inf'))
    
    smallest = min(arr[0], arr[1])
    second_smallest = max(arr[0], arr[1])
    largest = second_smallest
    second_largest = smallest
    
    for i in range(2, len(arr)):
        if arr[i] < smallest:
            second_smallest = smallest
            smallest = arr[i]
        elif arr[i] < second_smallest:
            second_smallest = arr[i]
        
        if arr[i] > largest:
            second_largest = largest
            largest = arr[i]
        elif arr[i] > second_largest:
            second_largest = arr[i]
    
    return (second_smallest, second_largest)

def main():
    n = int(input("Enter number of elements in array: "))
    
    if n < 2:
        print("Array must have at least 2 elements.")
        return
    
    arr = []
    print("Enter array elements:")
    for i in range(n):
        elem = int(input(f"Ele {i + 1}: "))
        arr.append(elem)
    
    result = find_second_small_large(arr)
    
    print(f"2nd Smallest is: {result[0]}")
    print(f"2nd Largest is: {result[1]}")

if __name__ == "__main__":
    main()
