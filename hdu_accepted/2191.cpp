#include<iostream>
#include<cstring>
using namespace std;
int v[500],w[500],h;
int dp[102];
void make(int weight,int value,int num)
{
    for(int i=1;num>i;i*=2)
    {
        num-=i;
        v[h]=i*value;
        w[h]=i*weight;
        h++;
    }
    if(num)
    {
        v[h]=num*value;
        w[h]=num*weight;
        h++;
    }
}
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,weight,value,num;
        cin>>n>>m;
        h=1;
        while(m--)
        {
            cin>>weight>>value>>num;
            make(weight,value,num);
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<h;i++)
            for(int j=n;j>=w[i];j--)
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        cout<<dp[n]<<endl;
    }
    return 0;
}