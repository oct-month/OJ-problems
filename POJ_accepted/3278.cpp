#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n,k;
int visit[100005];
int bfs()
{
    queue<int> Q;
    visit[n]=1;
    Q.push(n);
    while(!Q.empty())
    {
        int tap=Q.front();
        Q.pop();
        if(tap-1>=0&&visit[tap-1]==0)
        {
            Q.push(tap-1);
            visit[tap-1]=1+visit[tap];
        }
        if(tap+1<100001&&visit[tap+1]==0)
        {
            Q.push(tap+1);
            visit[tap+1]=1+visit[tap];
        }
        if(2*tap<100001&&visit[2*tap]==0)
        {
            Q.push(2*tap);
            visit[2*tap]=1+visit[tap];
        }
    }
    return visit[k]-1;
}
int main()
{
    while(cin>>n>>k)
    {
        memset(visit,0,sizeof(visit));
        if(n<k)cout<<bfs()<<'\n';
        else cout<<n-k<<'\n';
    }
    return 0;
}