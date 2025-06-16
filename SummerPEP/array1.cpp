// Given an array of size N , range 0 to N inclusive, find the missing element
#include <bits/stdc++.h>
using namespace std;
int findMissingElement(int arr[],int size)
{
    int sum=0;
    int actual = (size* (size+1))/2;
    for(int i =0;i<=size;i++)
    {
        sum+=arr[i];
    }
    int ans = actual - sum;
    return ans;
}
int main()
{
    int arr[100];
    int size;
   cout<<"Enter size: "<<endl;
   cin>>size;
   cout<<"Enter elements: "<<endl;
   for(int i =0;i<size;i++)
   {
    cin>>arr[i];
   }
   cout<<findMissingElement(arr,size);
    return 0;
}