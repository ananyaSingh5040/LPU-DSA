#include <bits/stdc++.h>
using namespace std;
void isPalindrome(string s) {


        for(int ch = 0; ch < s.length(); ch++)
      {
        if(s[ch] >= 'A' && s[ch] <= 'Z')
            s[ch] = s[ch] - 'A' + 'a';
      }
      cout<<s;
        
        
    }
int main()
{
    string s = "AmanaplanacanalPanama";
    isPalindrome(s);
    return 0;
}