// n^th fibonnaci number
#include <bits/stdc++.h>
using namespace std;
int NthFib (int n)
{
    if(n <= 1) return n;
    return NthFib(n - 1) + NthFib(n - 2);
}
int main()
{
    int n;
    cout<<"Enter N: "<<endl;
    cin>>n;
    cout<<"The Nth Fibonnaci term is: "<<NthFib(n);
    return 0;
}