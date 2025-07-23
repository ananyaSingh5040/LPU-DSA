#include <bits/stdc++.h>
using namespace std;
bool anagram(string s1, string s2)
{
    // BRUTE FORCE = O(n^2)
    // if(s1.length()!= s2.length()) return false;
    // for(int i = 0; i< s1.length(); i++)
    // {
    //     int count = 0;
    //     for(int j = 0; j< s2.length();j++)
    //     {
    //         if(s1[i]==s2[j])
    //         {
    //             count++;
    //             break;
    //         }
    //     }
    //     if(count < 1)
    //     return false;
    // }
    // return true;

    
    // BETTER APPROACH = O(n log n) {SORTING}
    // if (s1.length() != s2.length())
    //     return false;
    // sort(s1.begin(), s1.end());
    // sort(s2.begin(), s2.end());
    // return s1 == s2;

    // OPTIMAL APPROACH = 0(n) {Frequency array}
    unordered_map<char,int> fq;
    for(auto it: s1) fq[it]++;
    for(auto it: s2) fq[it]--;

    for(auto it: fq)
    {
        if(it.second != 0)
        return false;
    }
    return true;
}
int main()
{
    string s1, s2;
    cout << "Enter string 1: " << endl;
    cin >> s1;
    cout << "Enter string 2: " << endl;
    cin >> s2;
    int ans = anagram(s1, s2);
    ans ? cout << "The given string is an anagram!" : cout << "The given string is not an anagram";
    return 0;
}