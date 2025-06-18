#include <bits/stdc++.h>
using namespace std;
int sumOfDigits(int n) {
        
        int sum = 0;
        while(n>0)
        {
            sum+=n%10;
            n= n/10;
        }
        return sum;
        
    }
int main()
{
     int arr[100];
    int size;
    cout << "Enter size: " << endl;
    cin >> size;
    cout << "Enter elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    return 0;
}