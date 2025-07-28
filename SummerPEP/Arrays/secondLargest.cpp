// Find the second largest element in an array where all elements are unique
#include <bits/stdc++.h>
using namespace std;
int secondLargest(int arr[], int size)
{
    int largest = INT_MIN;
    int secondLargest = arr[0];
    for(int i =0; i<size;i++)
    {
        if(arr[i]>largest)
        {
            secondLargest=largest;
            largest = arr[i];
        }
    }
    return secondLargest;
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
    cout << "Second Largest Element: " << secondLargest(arr, size);
    return 0;
}