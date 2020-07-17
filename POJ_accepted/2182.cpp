#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int ennd[8001];
int ans[8001];
bool visit[8001];
int find(int n)
{
    int i=1;
    while(n--)
    {
        if(visit[i])n++;
        i++;
    }
    while(visit[i])i++;
    return i;
}
int main()
{
    int N;
    while(~scanf("%d",&N))
    {
        memset(visit,0,sizeof(visit));
        for(int i=2;i<=N;i++)
        {
            scanf("%d",ans+i);
        }
        ans[1]=0;
        ennd[N]=ans[N]+1;
        visit[ans[N]+1]=true;
        for(int i=N-1;i>=1;i--)
        {
            int tap=find(ans[i]);
            ennd[i]=tap;
            visit[tap]=true;
        }
        for(int i=1;i<=N;i++)printf("%d\n",ennd[i]);
    }
    return 0;
}