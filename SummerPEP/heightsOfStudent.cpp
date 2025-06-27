#include <bits/stdc++.h>
using namespace std;
void heightsOfStudents(vector<int> &arr)
{
    for(int i = 0; i < arr.size() - 1; i++)
    {
        for(int j = 0; j < arr.size() - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            swap(arr[j],arr[j + 1]);
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
    heightsOfStudents(arr);
     for(int i = 0; i < arr.size(); i++)
    {
        cout<< arr[i]<<" ";
    }
    return 0;
}
// 155 162 167 180 150 