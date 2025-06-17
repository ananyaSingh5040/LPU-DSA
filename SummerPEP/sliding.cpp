// Sliding window
#include <bits/stdc++.h>
using namespace std;
void findSubarraySum (vector<int> arr, int target)
{
    int n = arr.size();
    int prev = 0;
    int curr = 0;
    int sum = 0;
    bool found = false;
    while(curr<n)
    {
        if(sum<target)
        {
            sum+=arr[curr];
            curr++;
        }
        else if(sum>target)
        {
            sum-=arr[prev];
            prev++;
        }
        else
        {
            cout<<"Subarray found from index "<<prev<<" to index "<<curr;
           found = true;
           break;
        }

        
    }
    if(!found) cout<<"No subarray found";
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
    findSubarraySum(arr,20);
    return 0;
}