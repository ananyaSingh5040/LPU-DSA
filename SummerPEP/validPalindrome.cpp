#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s) {


        for(int ch = 0; ch < s.length(); ch++)
      {
        if(s[ch] >= 'A' && s[ch] <= 'Z')
            s[ch] = s[ch] - 'A' + 'a';
      }
      string st = "";
     for(int ch = 0; ch < s.length(); ch++)
        {
            if(s[ch] >= 'a' && s[ch] <= 'z')
            st += s[ch];
        }
       if(st == s)
       return true;
       else
       return false;        
        
    }
int main()
{
    string s = "Aman,aplanacanal: Panama";
    cout<<isPalindrome(s);
    return 0;
}