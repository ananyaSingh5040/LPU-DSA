#include <bits/stdc++.h>
using namespace std;
int squareRootInt(int n)
{
    int ans = 0;
    // for(int i = 1; i <= n/2; i++)
    // {
    //     if(i*i <= n)
    //     {
    //         ans = i;
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }
    int low = 0;
    int high = n - 1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        int sq = mid * mid;
        if(sq == n)
        {
            ans = mid;
            break;
        }
        else if (sq < n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }

    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<squareRootInt(n);
    return 0;
}