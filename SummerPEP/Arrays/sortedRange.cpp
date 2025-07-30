#include <bits/stdc++.h>
using namespace std;
int missingElement (vector<int> arr)
{
    int n = arr.size();
    int low = 0;
    int high = n -1;
    int ans = 0;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == mid)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            ans = mid;
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
    cout<<"Missing Element: "<<missingElement(arr);
    return 0;
}