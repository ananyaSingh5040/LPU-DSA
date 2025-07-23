#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5] = {1,2,3,4,5};
    int presum[5];

    presum[0]= arr[0];
    for(int i = 1; i< 5; i++)
    {
        presum[i] = presum[i-1] + arr[i];
    }
    
    return 0;
}