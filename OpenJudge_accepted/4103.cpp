#include<iostream>
using namespace std;
int num;
int go(int i,int j,int direc,int low)
{
    if(low==0)
    {
        num++;
        return 1;
    }
    if(direc!=2)go(i-1,j,1,low-1);
    if(direc!=1)go(i+1,j,2,low-1);
    go(i,j+1,3,low-1);
}
int main()
{
    int n;
    while(cin>>n)
    {
        num=0;
        go(30,1,0,n);
        cout<<num<<endl;
    }
    return 0;
}