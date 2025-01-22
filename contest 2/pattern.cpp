#include <iostream>
using namespace std;
int main()
{
    int size,middle;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i==size/2 && j==size/2)
            {
                cout<<"X";
                continue;
            }
            else if(i==j)
            {
                cout<<"\\";
            }
            else if(j==size-i-1)
            {
                cout<<"/";
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
   
    return 0;
}