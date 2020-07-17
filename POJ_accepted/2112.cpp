#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define INTMAX 0xfffffff
int K,C,M;
int mp[250][250];
int map[250][250];//跑最大流用的,0表示无路
void floyd()
{
    for(int i=1;i<=K+C;i++)
        for(int j=1;j<=K+C;j++)
            for(int v=1;v<=K+C;v++)
                if(mp[j][i]+mp[i][v]<mp[j][v])mp[j][v]=mp[j][i]+mp[i][v];
}
int depth[250];
struct node
{
    int point;
    int deep;
};
int bfs_c()
{
    memset(depth,-1,sizeof(depth));
    queue<node> Q;
    Q.push({0,0});
    depth[0]=0;
    while(!Q.empty())
    {
        node tap=Q.front();
        Q.pop();
        for(int i=0;i<=K+C+1;i++)
        {
            if(depth[i]==-1&&map[tap.point][i]>0)
            {
                Q.push({i,tap.deep+1});
                depth[i]=tap.deep+1;
            }
        }
    }
    if(depth[K+C+1]==-1)return 0;
    else return 1;
}
int dinic()
{
    int edn=K+C+1;
    deque<int> Q;
    bool visit[250];
    int sum=0;
    while(bfs_c())
    {
        Q.clear();
        memset(visit,0,sizeof(visit));
        Q.push_back(0);
        visit[0]=true;
        while(!Q.empty())
        {
            int v=Q.back();
            if(v==edn)
            {
                int minline=INTMAX,minpoint;
                for(int i=1;i<Q.size();i++)
                {
                    int f=Q[i-1],e=Q[i];
                    if(minline>map[f][e])
                    {
                        minline=map[f][e];
                        minpoint=f;
                    }
                }
                sum+=minline;
                for(int i=1;i<Q.size();i++)
                {
                    int f=Q[i-1],e=Q[i];
                    map[f][e]-=minline;
                    map[e][f]+=minline;
                }
                while(Q.back()!=minpoint)
                {
                    visit[Q.back()]=false;
                    Q.pop_back();
                }
            }
            else 
            {
                int i;
                for(i=0;i<=edn;i++)
                {
                    if(!visit[i]&&(depth[v]+1==depth[i])&&map[v][i]>0)
                    {
                        visit[i]=true;
                        Q.push_back(i);
                        break;
                    }
                }
                if(i>edn)//没有下一个点
                {
                    Q.pop_back();
                }
            }
        }
    }
    return sum;
}
void made(int mid)
{
    memset(map,0,sizeof(map));
    for(int i=1;i<=K;i++)map[0][i]=M;//0点为源点
    for(int i=K+1;i<=K+C;i++)map[i][K+C+1]=1;//K+C+1为汇点
    for(int i=1;i<=K;i++)
        for(int j=K+1;j<=K+C;j++)
            if(mp[i][j]<=mid)map[i][j]=1;
}
int main()
{
    while(~scanf("%d %d %d",&K,&C,&M))
    {
        for(int i=1;i<=K+C;i++)
            for(int j=1;j<=K+C;j++)
            {
                scanf("%d",&mp[i][j]);
                if(!mp[i][j])mp[i][j]=INTMAX;
            }
        floyd();//获取奶牛到每个挤奶点的最短距离
        int low=0,top=INTMAX,mid;
        while(low<top)
        {
            mid=(top+low)/2;
            made(mid);
            if(dinic()<C)low=mid+1;
            else top=mid;
        }
        mid=(top+low)/2;
        printf("%d\n",mid);
    }
    return 0;
}
//https://blog.csdn.net/u012860063/article/details/46952677