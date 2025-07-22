// Given a sorted array find the largest value less than or equal to x
#include <bits/stdc++.h>
using namespace std;
int largest(vector<int> arr, int x)
{
    int start = 0;
    int end = arr.size() - 1;
    int ans = 0;
    while(start <=end)
    {
        int mid = start + (end - start)/2;
        if(arr[mid] <= x)
        {
            ans = arr[mid];
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
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
    cout<<"Enter element: "<<endl;
    cin>>target;
    cout<<"Element which is smaller than or equal to the given target is : "<<largest(arr,target);
    return 0;
}