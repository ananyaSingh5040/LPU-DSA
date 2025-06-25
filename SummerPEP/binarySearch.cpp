#include <bits/stdc++.h>
using namespace std;
int binarySearch (int n, int target)
{
    int start = 0;
    int end = n - 1;
    int ans = 0;
    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        if(mid < target)
    {
        start = mid + 1;
    }
    else if(mid > target)
    {
        end = mid;
    }
    else
    {
        ans =  mid;
        break;
    }
    }
    return ans;
}
int main()
{
    int n, target ;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter target: ";
    cin>>target;
    cout<<"Missing number is: "<<binarySearch(n,target);
    return 0;
}