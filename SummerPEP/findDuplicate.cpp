// Find duplicates har element ek baari, find duplicate
#include <bits/stdc++.h>
using namespace std;
int findDuplicate(int arr[],int size)
{
    int ans = 0;
    unordered_map<int,int> mpp;
    // pehla index dusra number of times
    for(int i = 0;i<size;i++)
    {
        mpp[arr[i]]++;
    }
    for(auto it : mpp)
    {
        if(it.second>1)
        ans = it.first;
    }
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
   cout<<"Duplicate Element: "<<findDuplicate(arr,size);
    return 0;
    return 0;
}