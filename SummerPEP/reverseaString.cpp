#include <bits/stdc++.h>
using namespace std;
void reverseString(string s)
{
int start = 0;
int end = s.length() - 1;
while(start<end)
{
    swap(s[start],s[end]);
    start++;
    end--;
}
cout<<s<<endl;
}
int main()
{
    string s;
    cin>>s;
    reverseString(s);
    return 0;
}