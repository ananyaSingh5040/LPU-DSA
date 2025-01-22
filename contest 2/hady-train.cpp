#include <iostream>
using namespace std;
int main()
{
    int seat_number;
    cin>>seat_number;
    int row= seat_number/4;
    int col= seat_number%4;
    if(row%2!=0)
    {
        switch(col){
            case 0:
            col = 3;
            break;
            case 1:
            col= 2;
            break;
            case 2:
           col=1;
            break;
            case 3:
            col=0;
            break;

        }
    }
    cout<<row<<" "<<col;
    return 0;
}