#include<iostream>
using namespace std;
long long a[51][51]={0};
int main()
{
   int N,x,y;
   cin>>N;
   for(int i=1;i<=50;i++)//斐波那契数列
        for(int j=i+1;(j<=i+2)&&j<=50;j++)
            a[i][j]=j-i;
   for(int i=1;i<=50;i++)
       for(int j=i+3;j<=50;j++)
           a[i][j]=a[i][j-1]+a[i][j-2];
    for(int i=0;i<N;i++)
    {
        cin>>x>>y;
        cout<<a[x][y]<<endl;
    }
    return 0;
}