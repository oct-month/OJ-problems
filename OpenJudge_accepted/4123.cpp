#include<iostream>
#include<cstring>
using namespace std;
int T,n,m,x,y,endin;
int ans[16][16];
int a1[8]={1,2,2,1,-1,-2,-2,-1};
int b1[8]={2,1,-1,-2,-2,-1,1,2};
int dfs(int x,int y,int num)
{
    if(num==0){endin++;return 1;}
    for(int i=0;i<8;i++)
    {
        int tx=x+a1[i];
        int ty=y+b1[i];
        if(tx>=0&&ty>=0&&tx<n&&ty<m&&ans[tx][ty]==0)
        {
            ans[tx][ty]=1;
            dfs(tx,ty,num-1);
            ans[tx][ty]=0;
        }
    }
    return 0;
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>x>>y;
        endin=0;
        memset(ans,0,sizeof(ans));
        ans[x][y]=1;
        dfs(x,y,n*m-1);
        cout<<endin<<endl;
    }
    return 0;
}