#include <bits/stdc++.h>
using namespace std;
int squareRootInt(int n)
{
    int ans = 0;
    for(int i = 1; i <= n/2; i++)
    {
        if(i*i <= n)
        {
            ans = i;
        }
        else
        {
            break;
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