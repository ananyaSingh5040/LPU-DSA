#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;
    while(start<=end)
    {
        if(s[start]!=s[end])
        return false;

        start++;
        end--;
    }
    return true;
}
int main()
{
    string s;
    getline(cin,s);
    if(isPalindrome(s))
    cout<<"The given string is palindrome";
    else
    cout<<"The given string is not a palindrome";
    return 0;
}