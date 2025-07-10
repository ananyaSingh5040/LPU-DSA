#include <bits/stdc++.h>
using namespace std;
void isPalindrome(string s) {


        for(char ch: s)
        {
            if(s[ch] >= 'A' && s[ch] <='Z')
            {
                s[ch] = s[ch] - 'a';
                cout<<ch;
            }
        }
        
        
    }
int main()
{
    string s = "AmanaplanacanalPanama";
    isPalindrome(s);
    return 0;
}