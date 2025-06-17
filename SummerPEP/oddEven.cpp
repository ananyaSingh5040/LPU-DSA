// Find number of odd and even elements in an array
#include <bits/stdc++.h>
using namespace std;
void oddEvenCount(int arr[],int size)
{
    int even = 0;
    int odd = 0;
    for(int i = 0; i<size; i++)
    {
        if(arr[i]%2==0)
        even++;
        else
        odd++;
    }
    cout<<"Count of Even elements: "<<even<<endl;
    cout<<"Count of Odd elements: "<<odd<<endl;
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
    oddEvenCount(arr,size);
    return 0;
}