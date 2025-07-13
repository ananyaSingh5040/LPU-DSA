#include <bits/stdc++.h>
using namespace std;
bool validParenthesis(string s)
{
    int count = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            count++;
        else
            count--;
    }
    return (count == 0) ? true : false;
}
int main()
{
    string s = "((())";
    (validParenthesis(s)) ? cout << "True" : cout << "False";

    return 0;
}