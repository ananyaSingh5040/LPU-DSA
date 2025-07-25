#include <bits/stdc++.h>
using namespace std;
void printMatrix( int arr[][100], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
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
    printMatrix(arr,row,col);
    return 0;
}