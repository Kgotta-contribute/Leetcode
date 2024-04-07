// MUCH BETTER, EASY & EFFICIENT
#include <iostream>
#include <vector>
using namespace std;

vector<int> moveZeros(int n, vector<int> a) {
    int nonZeroIndex = 0; // Index to place non-zero elements
    
    for(int i = 0; i < n; i++) {
        if(a[i] != 0) {
            a[nonZeroIndex++] = a[i]; // Place non-zero elements at the front
        }
    }
    
    for(int i = nonZeroIndex; i < n; i++) {
        a[i] = 0; // Fill the remaining positions with zeros
    }
    
    return a;
}

int main() {
    vector<int> arr = {7, 6, 5, 4, 0, 0, 1, 3, 0, 7};
    int n = arr.size();

    vector<int> ans = moveZeros(n, arr);

    for(auto &it : ans) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}


========================================================================

java 

import java.util.ArrayList;
import java.util.List;

public class Main {

  public static List<Integer> moveZeros(int n, List<Integer> a) {
    int nonZeroIndex = 0; // Index to place non-zero elements

    for(int i = 0; i < n; i++) {
      if(a.get(i) != 0) {
        a.set(nonZeroIndex++, a.get(i)); // Place non-zero elements at the front
      }
    }

    for(int i = nonZeroIndex; i < n; i++) {
      a.set(i, 0); // Fill the remaining positions with zeros
    }

    return a;
  }

  public static void main(String[] args) {
    List<Integer> arr = List.of(7, 6, 5, 4, 0, 0, 1, 3, 0, 7);
    int n = arr.size();

    List<Integer> ans = moveZeros(n, new ArrayList<>(arr));

    for(Integer it : ans) {
      System.out.print(it + " ");
    }
    System.out.println();
  }
}


// #include <iostream>
// #include<vector>
// using namespace std;

// vector<int> moveZeroes(int n , vector<int> a)
// {
// 	int j = -1;
	
// 	for(int i=0; i<n ; i++)
// 	{
// 		if(a[i] == 0)
// 		{
// 			j=i;
// 			break;
// 		}
// 	}
	
// 	if(j == -1) return a;	//Indicates no non zero elements
	
// 	for(int i=j+1; i<n; i++)
// 	{
// 		if( a[i] != 0 )
// 		{
// 			swap(a[j], a[i]);
// 			j++;
// 		}
// 	}
// 	return a;
// }
// int main()
// {
// 	vector<int> arr = {7,6,5,4,0,0,1,3,0,7};			//int n = 10;//sizeof(arr)/sizeof(arr[0]);
// 	int n = arr.size();

// 	vector<int> ans = moveZeroes(n , arr);
	
// 	for(auto &it : ans)
// 	{
// 		cout<<it<<" ";
// 	}
// 	cout<<endl;
	
// 	return 0;
// }
// /*
// The auto &it : ans
// is a range based loop used to iterate over the vector answer
// auto &it declares a reference variable 'it' that points to each element of the vector answer
// */