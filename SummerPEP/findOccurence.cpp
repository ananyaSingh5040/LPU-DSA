#include <bits/stdc++.h>
using namespace std;
void findFirstOccurence(vector<int> arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int first = -1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] < target)
        {
            low = mid + 1;
        }
        else if(arr[mid] > target)
        {
            high = mid;
        }
        else
        {
            first = mid;
            high = mid - 1;
            
        }
    }
    cout<<"First Occurence at Index: "<<first;
    
}
void findLastOccurence(vector<int> arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int last = -1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] < target)
        {
            low = mid + 1;
        }
        else if(arr[mid] > target)
        {
            high = mid;
        }
        else
        {
            last = mid;
            low = mid + 1;
            
        }
    }
    cout<<endl<<"Last Occurence at Index: "<<last;
    
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
    cout<<"Enter element which you need to know the occurence for: "<<endl;
    cin>>target;
    findFirstOccurence(arr,target);
    findLastOccurence(arr,target);
    return 0;
}