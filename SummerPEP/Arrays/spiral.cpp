#include <bits/stdc++.h>
using namespace std;
void printSpiral(int arr[][100], int row, int col)
{
    int top = 0;
    int bottom = row - 1;
    int left = 0;
    int right = col - 1;
    while (top <= bottom && left <= right)
    {
        // Top Row
        for (int i = left; i <= right; i++)
            cout << arr[top][i]<<" ";
        top++;
        cout<<endl;

        // Right Row
        for (int i = top; i <= bottom; i++)
            cout << arr[i][right]<<" ";
        right--;
        cout<<endl;

        // Bottom Row
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                cout << arr[bottom][i]<<" ";
            bottom--;
            cout<<endl;
        }
        // Left Row
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                cout << arr[i][left]<<" ";
            left++;
            cout<<endl;
        }
    }
    cout << endl;
}

int main()
{
    int row, col;
    cout << "Enter row size: " << endl;
    cin >> row;
    cout << "Enter col size: " << endl;
    cin >> col;
    int arr[row][100];
    cout << "Enter Elements: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    printSpiral(arr, row, col);
    return 0;
}