#include <bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> &arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = i ; j > 0; j--)
        {
            if(arr[j-1] > arr[j])
                swap(arr[j-1],arr[j]);
            else
                break;
        }
    }
    
}
int main()
{
    int size;
    cout << "Enter size: " << endl;
    cin >> size;
    vector<int> arr(size);
    cout << "Enter elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    insertionSort(arr);
    cout<<"Priniting Sorted Array: "<<endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i]<<" ";
    }
    
    return 0;
}