// Check if an array has duplicates or not, do not use extra space
#include <bits/stdc++.h>
using namespace std;
bool checkDuplicates(vector<int> arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = i + 1; j < arr.size(); j++)
        {
            if(arr[j]==arr[i])
            {
                return true;
            }
        }
    }
    return false;
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
    int ans = checkDuplicates(arr);
    ans ? cout<<"The array contains duplicate elements"<<endl : cout<<"The array does not have any duplicate elements"<<endl;
    return 0;
}