#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int N;
int map[1001][1001];
int sg[1001];
int dfs(int t)
{
    if(sg[t]!=-1)return sg[t];
    bool visit[1001];
    memset(visit,0,sizeof(visit));
    for(int i=0;i<N;i++)
    {
        if(map[t][i])visit[dfs(i)]=true;
    }
    for(int i=0;i<N;i++)
        if(!visit[i])return sg[t]=i;
}
int main()
{
    while(~scanf("%d",&N))
    {
        memset(map,0,sizeof(map));
        memset(sg,-1,sizeof(sg));
        for(int i=0;i<N;i++)
        {
            int k;//i点的可达点数目
            scanf("%d",&k);
            if(!k)sg[i]=0;
            while(k--)
            {
                int t;//可达点
                scanf("%d",&t);
                map[i][t]=1;//i到t可达
            }
        }
        int m;//m个起始点
        while(scanf("%d",&m)&&m)
        {
            int ans=0,tp;
            while(m--)
            {
                scanf("%d",&tp);
                ans=ans^dfs(tp);
            }
            if(ans)printf("WIN\n");
            else printf("LOSE\n");
        }
    }
    return 0;
}
//https://blog.csdn.net/acm_zl/article/details/9448041