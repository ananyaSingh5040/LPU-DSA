#include <bits/stdc++.h>
using namespace std;
int transitionIndex(vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;
    int ans = 0;
    while(start <=end)
    {
        int mid = start + (end - start)/2;
        if(arr[mid] < 1)
        {
            start = mid + 1;
        }
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }
    return ans;
}
int main()
{
     int size, target,number;
    cout << "Enter size: " << endl;
    cin >> size;
    vector<int> arr(size);
    cout << "Enter elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout<<"The transition Index is: "<<transitionIndex(arr);
    return 0;
}