#include<iostream>
using namespace std;

int bin_num;
int flag=true,digit;

void GET_DETAILS()
{
    cout<<"Enter The Binary Number: ";
    cin>>bin_num;
    cout<<endl;
}

void PROCESS()
{
    while(bin_num!=0)
    {
        digit=bin_num%10;
        if(digit==0 || digit==1)
            flag=true;
        else
        {
            flag=false;
            break;
        }
        bin_num=bin_num/10;
    }
}

void PRINT()
{
    if(flag)
        cout<<"Number Is Binary"<<endl;
    else
        cout<<"Number is not Binary"<<endl;
}

int main()
{
    GET_DETAILS();
    PROCESS();
    PRINT();
    return 0;
}