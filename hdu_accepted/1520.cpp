#include<iostream>
#include<cstring>
#include<set>
using namespace std;
int bus[6001];
bool visit[6001];
int n;
int dp[2][6001];
int bingc[6001];
set<int> haizi[6001];
int max(int a,int b)
{
    return a>b?a:b;
}
void make(int v)
{
    visit[v]=1;
    while(!haizi[v].empty())
    {
        int i=*haizi[v].begin();
        haizi[v].erase(haizi[v].begin());
        if(!visit[i])
        {
            make(i); 
            dp[1][v]+=dp[0][i];
            dp[0][v]+=max(dp[1][i],dp[0][i]);
        }
    }
}
void bing(int a,int b)
{
    int e=b;
    while(bingc[e]!=e)e=bingc[e];
    bingc[a]=e;
    bingc[b]=e;
}
int main()
{
    while(~scanf("%d",&n))
    {
        memset(visit,0,sizeof(visit));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            scanf("%d",dp[1]+i);
        int a,b;
        for(int i=1;i<=n;i++){bus[i]=i;bingc[i]=i;}
        while(scanf("%d %d",&a,&b)&&a&&b)
        {
            bus[a]=b;
            bing(a,b);
            haizi[b].insert(a);
        }
        int root=1;
        while(bingc[root]!=root)root=bingc[root];//找到根节点
        make(root);
        printf("%d\n",max(dp[0][root],dp[1][root]));
    }
    return 0;
}