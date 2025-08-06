// find sum of elements of array using recursion.
#include <bits/stdc++.h>
using namespace std;
int sum (vector<int> arr,int index)
{

    if(index == arr.size()) return 0;
    return arr[index] + sum(arr, index + 1);
      
     
}
int main()
{
   
    int size;
    cout << "Enter size: " << endl;
    cin >> size;
    vector<int> arr(size);
    cout << "Enter elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout<<"Sum using recursion: "<<sum(arr,0);
    return 0;
}