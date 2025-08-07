#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp;
    int left = start;
    int right = mid + 1;
    // left smaller than mid rakhna hai
    // right smaller than end rakhna hai
    // if left badu toh add left, if right badu toh add right
    // out of bound gaya toh append remaining
    while(left <= mid && right <= end)
    {
       if(arr[left] > arr[right])
       {
        temp.push_back(arr[left]);
        left++;
       }
       else
       {
        temp.push_back(arr[right]);
        right++;
       }
    }
    while(left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= end)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = 0; i < temp.size(); i++)
    {
        arr[start + i] = temp[i];
    }
 
   
}

void mergeSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{
    vector<int> arr = {5, 2, 9, 1, 6, 3};
    mergeSort(arr, 0, arr.size() - 1);
    cout << "Sorted in descending order: ";
    for (int num : arr)
        cout << num << " ";
    return 0;
}
