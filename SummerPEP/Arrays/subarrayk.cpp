#include <bits/stdc++.h>
using namespace std;
// Count the number of subarray of size k, whose sum is greater than or equal to s
int subArray(vector<int> arr, int k, int s)
{
    int n = arr.size();
    int count = 0;
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];

    if (sum >= s)
        count++;
    for (int i = k; i < n; i++)
    {
        sum = sum - arr[i - k] + arr[i];

        if (sum >= s)
            count++;
    }
    return count;
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
    return 0;
}