#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int> arr)
{
    int mini, minimum;
    for(int i = 0; i < arr.size() - 1; i++)
    {
        mini = i;
        minimum = arr[i];
        for(int j = i; j < arr.size() - 1; j++)
        {
            if(arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        swap(arr[mini], arr[i]);
    }
}
int main()
{
    return 0;
}