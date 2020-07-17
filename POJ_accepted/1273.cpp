#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
//#include<vector>
using namespace std;
int map[201][201];
int depth[201];//层次数
//vector<int> dept[201];
int n,m;//n条边，m个点
struct node
{
    int a;//点
    int dep;//层次数
};
int bfs(int h)//从h点开始广搜分层
{
    memset(depth,-1,sizeof(depth));
    //for(int i=0;i<m;i++)dept[i].clear();
    queue<node> Q;
    depth[h]=0;
    //dept[0].push_back(h);
    Q.push({h,0});
    while(!Q.empty())
    {
        node tap=Q.front();
        Q.pop();
        for(int i=1;i<=m;i++)
        {
            if(depth[i]==-1&&map[tap.a][i]!=0)
            {
                Q.push({i,tap.dep+1});
                depth[i]=tap.dep+1;
                //dept[tap.dep+1].push_back(i);
            }
        }
    }
    if(depth[m]==-1)return 0;//找不到汇点
    return 1;
}
bool visit[201];
int dinic()
{
    stack<int> S;
    stack<int> Stap;
    int sum=0;
    int min_node=0;
    while(bfs(1))
    {
        while(!S.empty())S.pop();
        while(!Stap.empty())Stap.pop();
        S.push(1);
        memset(visit,0,sizeof(visit));
        visit[1]=1;
        while(!S.empty())
        {
            int nd=S.top();
            if(nd==m)//当nd 为汇点
            {
                Stap.push(nd);
                S.pop();
                int min_l=0x7fffffff;//最小边
                while(!S.empty())
                {
                    int tap=S.top();
                    min_l=min(map[tap][nd],min_l);
                    nd=tap;
                    Stap.push(tap);
                    S.pop();
                }
                sum+=min_l;
                nd=Stap.top();
                S.push(nd);
                Stap.pop();
                min_node=0;//最小边的起点
                while(!Stap.empty())
                {
                    int tap=Stap.top();
                    map[nd][tap]-=min_l;
                    map[tap][nd]+=min_l;
                    if(map[nd][tap]==0)min_node=nd;
                    nd=tap;
                    S.push(tap);
                    Stap.pop();
                }
                while(!S.empty()&&S.top()!=min_node)//回退
                {
                    visit[S.top()]=0;
                    S.pop();
                }
            }
            else
            {
                int i;
                for(i=1;i<=m;i++)
                {
                    if(!visit[i]&&depth[nd]+1==depth[i]&&map[nd][i]>0)
                    {
                        visit[i]=true;
                        S.push(i);
                        break;
                    }
                }
                if(i>m)S.pop();//没有下一个点
            }
        }
    }
    return sum;
}
int main()
{
    while(cin>>n>>m)
    {
        memset(map,0,sizeof(map));
        int a,b,v;
        while(n--)
        {
            cin>>a>>b>>v;
            map[a][b]+=v;
        }
        cout<<dinic()<<endl;
    }
    return 0;
}