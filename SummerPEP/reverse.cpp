// Reverse an array without using extra space
#include <bits/stdc++.h>
using namespace std;
void arrayReverse(int arr[], int size)
{
    int start =0;
    int end = size -1 ;
    while(start<end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end]= temp;
        start++;
        end--;
    }
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
   arrayReverse(arr,size);
   cout<<"Reversed Array: ";
   for(int i =0;i<size;i++)
   {
    cout<<arr[i]<<" ";
   }
    return 0;
}