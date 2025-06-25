#include <bits/stdc++.h>
using namespace std;
int sumOfString(string s){

    int sum = 0;
    for(int i = 0; i < s.length(); i++)
    {
        int numValue = s[i] - 'a' + 1;
        sum += numValue;
    }
    return sum;
}
int main()
{
    return 0;
}