// JAVA

import java.util.HashSet;
import java.util.Vector;

public class Main {
    static Vector<Integer> findUnion(int[] a1, int[] a2, int n, int m) {
        HashSet<Integer> set = new HashSet<>();
        Vector<Integer> union = new Vector<>();

        for (int i = 0; i < n; i++)
            set.add(a1[i]);
        for (int i = 0; i < m; i++)
            set.add(a2[i]);
        for (int val : set)
            union.add(val);
        return union;
    }

    public static void main(String[] args) {
        int n = 10, m = 7;
        int[] a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] a2 = {2, 3, 4, 4, 5, 11, 12};

        Vector<Integer> union = findUnion(a1, a2, n, m);

        System.out.println("Union of a1 & a2 is: ");
        for (int val : union)
            System.out.print(val + " ");
    }
}



// CPP

#include <bits/stdc++.h>
using namespace std;
vector<int> FindUnion(int a1[], int a2[], int n, int m)
{
    set<int> s;
    vector<int> Union;

    for(int i=0; i<n; i++)
        s.insert(a1[i]);        // s.insert(a1[9]) → s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    for(int i=0; i<m; i++)
        s.insert(a2[i]);        // s.insert(a2[6]) → s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
    for(auto &it : s)
        Union.push_back(it);    // Union.push_back(it) → Union = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
    return Union;
}
int main()
{
    int n = 10, m = 7;      // these are the sizes
    int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a2[] = { 2, 3, 4,4,5,11,12};
    vector<int> Union = FindUnion(a1, a2, n, m);
    cout<<"Union of a1 & a2 is : "<<endl;
    for(auto &val : Union)
        cout<<val<<" ";
    return 0;
}



// PYTHON

def find_union(a1, a2):
    # Use a set to store unique elements
    union_set = set(a1) | set(a2)
    
    # Convert the set to a sorted list
    union_list = sorted(union_set)
    
    return union_list

def main():
    n = 10
    m = 7
    a1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    a2 = [2, 3, 4, 4, 5, 11, 12]

    union = find_union(a1, a2)

    print("Union of a1 & a2 is:")
    print(" ".join(map(str, union)))

if __name__ == "__main__":
    main()





// METHOD 2 USING TWO-POINTERS CPP
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> FindUnion(int a1[], int a2[], int n, int m) 
// {
//   int i = 0, j = 0; 
//   vector< int > UnionArr; 
//   while (i < n && j < m) 
//   {
//     if (a1[i] <= a2[j]) 
//     {
//       if (UnionArr.size() == 0 || UnionArr.back() != a1[i])
//         UnionArr.push_back(a1[i]);
//       i++;
//     } 
//     else 
//     {
//       if (UnionArr.size() == 0 || UnionArr.back() != a2[j])
//         UnionArr.push_back(a2[j]);
//       j++;
//     }
//   }
//   while (i < n) // Any element left in array1
//   {
//     if (UnionArr.back() != a1[i])
//       UnionArr.push_back(a1[i]);
//     i++;
//   }
//   while (j < m) // If any element left in arr 2
//   {
//     if (UnionArr.back() != a2[j])
//       UnionArr.push_back(a2[j]);
//     j++;
//   }
//   return UnionArr;
// }

// int main()

// {
//   int n = 10, m = 7;
//   int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   int a2[] = {2, 3, 4, 4, 5, 11, 12}; 
//   vector < int > Union = FindUnion(a1, a2, n, m);
//   cout << "Union of Array1 & Array2 is  " << endl;
//   for (auto &val: Union)
//     cout << val << " ";
//   return 0;
// }
