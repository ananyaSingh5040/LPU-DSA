#include <bits/stdc++.h>
using namespace std;
int binarySearchInArray(vector<int> arr, int target)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int targetIndex = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else if (arr[mid] > target)
        {
            end = mid;
        }
        else
        {
            targetIndex = mid;
            break;
        }
    }
    return targetIndex;
}
int main()

{
    int size, target;
    cout << "Enter size: " << endl;
    cin >> size;
    vector<int> arr(size);
    cout << "Enter elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout<<"Enter element which you need to know the index for: "<<endl;
    cin>>target;
    int ans = binarySearchInArray(arr, target);
    (ans == -1) ? cout<<"The element was not present in the array" : cout<<"Element was found at Index: "<<ans;
    return 0;
}