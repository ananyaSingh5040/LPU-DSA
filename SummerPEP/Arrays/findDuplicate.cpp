// Find duplicates har element ek baari, find duplicate
#include <bits/stdc++.h>
using namespace std;
int findDuplicate(int arr[], int size)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < size; i++)
    {
        if (mpp.count(arr[i]))
        {
            return arr[i];
        }
      mpp[arr[i]]++;
    }
    return -1;
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
    cout << "Duplicate Element: " << findDuplicate(arr, size);
    return 0;
}