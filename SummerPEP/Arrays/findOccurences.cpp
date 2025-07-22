#include <bits/stdc++.h>
using namespace std;
int findFirstOcc(vector<int> arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    int firstOcc = -1;
    while(start <= end)
    {
        int mid = start + (end - start)/ 2;
        if(arr[mid] < target)
        {
            start = mid + 1;
        }
        else if(arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            firstOcc = mid;
            end = mid - 1;

        }
    }
    return firstOcc;
}
int findLastOcc(vector<int> arr, int target)
{
    int start = 0;
    int end = arr.size() -1 ;
    int lastOcc = -1;
    while(start <= end)
    {
        int mid = start +(end - start)/2;
        if(arr[mid] > target)
        {
            end = mid - 1;
        }
        else if(arr[mid] < target)
        {
            start = mid + 1;
        }
        else{
            lastOcc = mid;
            start = mid + 1;
        }
    }
    return lastOcc;
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
    cout<<"Enter element for occurence: "<<endl;
    cin>>number;
    int result1 = findLastOcc(arr,number);
    int result2 = findFirstOcc(arr,number);
    int ans = (result1 - result2) + 1;
    cout<<"Number of times the element was seen in this array is: "<<ans;
    return 0;
}