// 0 to N , find prime number count
#include <bits/stdc++.h>
using namespace std;
int primeCount(int n)
{
    int count =0;
    for(int i =2;i<=n;i++)
    {
        if(i%2!=0)
        count++;
    }
    return count;
}
int main()
{
    int n;
    cout<<"Enter N: ";
    cin>>n;
    cout<<"Count of prime numbers are: "<<primeCount(n);
    return 0;
}