#include <bits/stdc++.h>
using namespace std;
int indexRange(vector<int> arr, int index , int k)
{
    int range1 = arr[index] - k;
    int range2 = arr[index] + k;
}
int main()
{
     int size, k,index;
    cout << "Enter size: " << endl;
    cin >> size;
    vector<int> arr(size);
    cout << "Enter elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout<<"Enter index: "<<endl;
    cin>>index;
    cout<<"Enter k: "<<endl;
    cin>>k;
    cout<<"The numbers lying in the range index -k, index + k are: "<<indexRange(arr,index,k);
    return 0;
}