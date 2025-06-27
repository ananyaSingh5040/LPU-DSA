// 2) You are given an array of integers containing both even and odd numbers.
// Your task is to rearrange the array such that:
// •⁠  ⁠All even numbers come before all odd numbers, and
// •⁠  ⁠Even numbers are sorted in ascending order,
// •⁠  ⁠Odd numbers are also sorted in ascending order.
// eg - [2,5,1,6,8,3,7,4,9]
// output - [2,4,6,8,1,3,5,7,9]
#include <bits/stdc++.h>
using namespace std;
void yadaYada(vector<int> arr)
{
    int n = arr.size();
    vector<int> even;
    vector<int> odd;
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
            even.push_back(arr[i]);
        else
            odd.push_back(arr[i]);
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    result.insert(result.begin(), even.begin(), even.end());
    result.insert(result.end(), odd.begin(), odd.end());
    cout << "Re-arranged Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
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
    yadaYada(arr);

    return 0;
}
