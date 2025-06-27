#include <bits/stdc++.h>
using namespace std;
int insertionIndex (vector<int> arr, int number)
{
    int start = 0;
    int end = arr.size();
    int ans = arr.size();
    while(start < end)
    {
        int mid = start + (end - start)/2;
        if(arr[mid] >= number)
        {
           ans = mid;
           end = mid;
        }
        else
        {
            start = mid + 1;
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
    cout<<"Enter number which needs to be inserted: "<<endl;
    cin>>number;
    cout<<"Index of the given number in this particular array: "<<insertionIndex(arr, number);
    return 0;
}