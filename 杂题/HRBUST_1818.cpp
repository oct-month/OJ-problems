#include<iostream>
using namespace std;
int ans[120];//从1到i的总数
int mindp[120][120],maxdp[120][120];
int n;
int min2(int a,int b)
{
    int tap=0xfffffff,e;
    for(int i=a;i<b;i++)
    {
        e=mindp[a][i]+mindp[i+1][b]+ans[b]-ans[a-1];
        if(e<tap)tap=e;
    }
    return tap;
}
int max2(int a,int b)
{
    int tap=0,e;
    for(int i=a;i<b;i++)
    {
        e=maxdp[a][i]+maxdp[i+1][b]+ans[b]-ans[a-1];
        if(e>tap)tap=e;
    }
    return tap;
}
void dfs()
{
    for(int i=1;i<n;i++)//间隔i
        for(int j=1+i;j<=n;j++)
        {
            mindp[j-i][j]=min2(j-i,j);
            maxdp[j-i][j]=max2(j-i,j);
        }
}
int main()
{
    while(cin>>n)
    {
        ans[0]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>ans[i];
            ans[i]+=ans[i-1];
        }
        for(int i=0;i<=n;i++)maxdp[i][i]=mindp[i][i]=0;
        dfs();
        cout<<mindp[1][n]<<' '<<maxdp[1][n]<<endl;
    }   
    return 0;
}