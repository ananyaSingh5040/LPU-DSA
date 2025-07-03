// 1) You are given 2 sorted arrays, merge them into 1 sorted array.
// eg - a=[1,4,6,9], b=[3,5,6,7]. output = [1,3,4,5,6,6,7,9]
#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

       int p1 = m - 1;
       int p2 = n - 1;
       int k = m + n - 1;
       while(p2>=0)
       {
        if(p1>=0 && nums1[p1]>nums2[p2])
        { 
        nums1[k] = nums1[p1];
        p1--;
        }
        else
        {
        nums1[k] = nums2[p2];
        p2--;
        }
        k--;
       }
    }
int main()
{
    int size;
    cout << "Enter size for 1st array and add 0's for the remaining index: " << endl;
    cin >> size;
    vector<int> nums1(size);
    cout << "Enter elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> nums1[i];
    }
    int size2;
    cout << "Enter size for 2nd array: " << endl;
    cin >> size2;
    vector<int> nums2(size2);
    cout << "Enter elements: " << endl;
    for (int i = 0; i < size2; i++)
    {
        cin >> nums2[i];
    }
    merge(nums1, size - size2, nums2, size2);
    cout<<"Merged + Sorted Array: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<< nums1[i]<<" ";
    }
    return 0;
}