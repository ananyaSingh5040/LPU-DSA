#include <bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int> arr)
{
    for(int i = 0; i < arr.size() - 2; i++)
    {
        for(int j = 0; j < arr.size() - i - 2; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j],arr[j + 1]);
            }
        }
    }
    cout<<"Priniting Sorted Array: "<<endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i]<<" ";
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
    bubbleSort(arr);
    
    return 0;
}