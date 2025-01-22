#include <iostream>
using namespace std;
int main()
{
    long long int t,l,r;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>l>>r;
        long long int smallest= min(l,r);
        long long int largest= max(l,r);
        long long int sum= (((largest*(largest+1))/2) - ((smallest*(smallest+1))/2) )+ smallest;
        cout<<sum<<endl;
    }
    return 0;
}