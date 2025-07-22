#include <bits/stdc++.h>
using namespace std;
int sum(int arr[][100], int row, int col)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}
int main()
{
    int row, col;
    cout << "Enter row size: " << endl;
    cin >> row;
    cout << "Enter col size: " << endl;
    cin >> col;
    int arr[row][100];
   cout<<"Enter Elements: "<<endl;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"Sum of 2D array is : "<<sum(arr,row,col);

    return 0;
}