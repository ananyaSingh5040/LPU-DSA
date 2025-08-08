#include <bits/stdc++.h>
using namespace std;
void sortOnes(vector<int> &arr)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i]==0) count0++;
        else if(arr[i]==1)count1++;
        else count2++;
    }
    int i = 0;
    while(count0 != 0)
    {
        arr[i] = 0;
        i++;
        count0--;
    }
    while(count1 != 0)
    {
        arr[i] = 1;
        i++;
        count1--;
    }
    while(count2 != 0)
    {
        arr[i] = 2;
        i++;
        count2--;
    }

}
int main()
{
    int size;
    cout << "Enter size: " << endl;
    cin >> size;
    vector<int> arr(size);
    cout << "Enter elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    sortOnes(arr);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}