#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define INTMAX 0x4fffffff
int T,m,n,t;
struct node
{
    int up;//上界
    int low;//下界
    int v;
};
node map[250][250];
int G2[250][250],G[250][250];
struct node2
{
    int po;
    int de;
};
int depth[250];
bool fenc(int s,int t,int flag)//以s为源,t为汇分层
{
    int edn=m+n+1+2;
    if(flag==2)edn=m+n+1;
    memset(depth,-1,sizeof(depth));
    queue<node2> Q;
    depth[s]=0;
    Q.push({s,0});
    while(!Q.empty())
    {
        node2 tap=Q.front();
        Q.pop();
        for(int i=0;i<=edn;i++)
        {
            if(depth[i]==-1&&map[tap.po][i].v>0)
            {
                depth[i]=tap.de+1;
                Q.push({i,depth[i]});
            }
        }
    }
    if(depth[t]==-1)return 0;
    return 1;
}
int dinic(int s,int t,int flag)
{
    int sum=0;
    deque<int> Q;
    int edn=m+n+1+2;
    if(flag==2)edn=m+n+1;
    bool visit[250];
    while(fenc(s,t,flag))
    {
        memset(visit,0,sizeof(visit));
        Q.clear();
        Q.push_back(s);
        visit[s]=true;
        while(!Q.empty())
        {
            int nd=Q.back();
            if(nd==t)
            {
                int minline=INTMAX,minpoint;
                for(int i=1;i<Q.size();i++)
                {
                    int f=Q[i-1],e=Q[i];
                    if(map[f][e].v<minline)
                    {
                        minline=map[f][e].v;
                        minpoint=f;
                    }
                }
                sum+=minline;
                for(int i=1;i<Q.size();i++)
                {
                    int f=Q[i-1],e=Q[i];
                    map[f][e].v-=minline;
                    map[e][f].v+=minline;
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
                    if(!visit[i]&&depth[nd]+1==depth[i]&&map[nd][i].v>0)
                    {
                        Q.push_back(i);
                        visit[i]=true;
                        break;
                    }
                }
                if(i>edn)Q.pop_back();
            }
        }
    }
    return sum;
}
bool judge()
{
    int s=0,t=m+n+1;
    int x=t+1,y=t+2;//附加源x,附加汇y
    map[x][y].v=map[y][x].v=0;//y->x    x与y之间不连通
    int tap=0;
    for(int i=0;i<=t;i++)//建立等价网络
        for(int j=0;j<=t;j++)
        {
            map[i][j].v+=map[i][j].up-map[i][j].low;
            map[x][j].v+=map[i][j].low;
            map[i][y].v+=map[i][j].low;
            tap+=map[i][j].low;
        }
    map[t][s].v=INTMAX;//添加t->s的无穷边
     for(int i=1;i<=m+n;i++)
        for(int j=1;j<=m+n;j++)
            G2[i][j]=map[i][j].v;//做最大流之前，备份新图
    int sum=dinic(x,y,1);
    if(sum==tap)return 1;
    return 0;
}
int main()
{
    cin>>T;
    while(T--)
    {
        bool flag=true;
        cin>>m>>n;
        memset(map,0,sizeof(map));
        for(int i=1;i<=m;i++)
            for(int j=m+1;j<=m+n;j++)
                map[i][j].low=0,map[i][j].up=INTMAX;//下界初始化为0，上界无穷大
        for(int i=1;i<=m;i++)
        {
            cin>>map[0][i].low;//0为源点
            map[0][i].up=map[0][i].low;
        }
        for(int i=m+1;i<=m+n;i++)
        {
            cin>>map[i][m+n+1].low;
            map[i][m+n+1].up=map[i][m+n+1].low;//m+n+1为汇点
        }
        cin>>t;
        while(t--)
        {
            int a,b,d;
            char e;
            cin>>a>>b>>e>>d;
            int f1=a,f2=m+b,t1=a,t2=m+b;
            if(a==0)f1=1,t1=m;
            if(b==0)f2=m+1,t2=m+n;
            if(d<0)d=-1;
            for(int i=f1;i<=t1;i++)
                for(int j=f2;j<=t2;j++)
                    if(e=='>')map[i][j].low=max(map[i][j].low,d+1);
                    else if(e=='<')map[i][j].up=min(map[i][j].up,d-1);
                    else map[i][j].low=max(map[i][j].low,d),map[i][j].up=min(map[i][j].up,d);
        }
        for(int i=1;i<=m;i++)
            for(int j=m+1;j<=m+n;j++)
            {
                if(map[i][j].up<map[i][j].low)
                {
                    flag=false;
                    break;
                }
            }
        int sum1=judge();
        if(sum1==0||flag==false)cout<<"IMPOSSIBLE"<<endl;
        else
        {
            map[0][m+n+1].v=map[m+n+1][0].v=0;//去除t->s和s->t的边
            dinic(0,m+n+1,2);
            for(int i=1;i<=m+n;i++)
                for(int j=1;j<=m+n;j++)
                    G[i][j]=G2[i][j]-map[i][j].v+map[i][j].low;//原新图-残图+下界
            for(int i=1;i<=m;i++)
            {
                for(int j=m+1;j<=m+n;j++)
                {  
                    cout<<G[i][j];
                    if(j<m+n)cout<<' ';
                }
                cout<<endl;
            }
        }
        if(t)cout<<endl;
    }
    return 0;
}
/*这组数据把我卡死了*/
/*
1
200 20
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0*/