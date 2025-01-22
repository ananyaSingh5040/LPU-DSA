#include <iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
for(int i=0;i<n;i+=k)
{
    int min= INT_MAX;
    for(int j=i;j<i+k && j<n;j++)
    {
        if(arr[i]<min)
        {
            min= arr[i];
        }
    }
    cout<<min<<" ";
}
cout<<endl;
    return 0;
}