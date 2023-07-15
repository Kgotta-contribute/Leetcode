 #include <bits/stdc++.h>
using namespace std;
vector<int> FindUnion(int a1[], int a2[], int n, int m)
{
    set<int> s;
    vector<int> Union;

    for(int i=0; i<n; i++)
        s.insert(a1[i]);
    for(int i=0; i<m; i++)
        s.insert(a2[i]);
    for(auto &it : s)
        Union.push_back(it);
    return Union;
}
int main()
{
    int n = 10, m = 7;
    int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a2[] = { 2, 3, 4,4,5,11,12};
    vector<int> Union = FindUnion(a1, a2, n, m);
    cout<<"Union of a1 & a2 is : "<<endl;
    for(auto &val : Union)
        cout<<val<<" ";
    return 0;
}






// METHOD 2 USING TWO-POINTERS
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
