#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int N,M;
char map[45][45];
int ans1,ans2;
bool judge(int x,int y)
{
	if(x>=0&&x<N&&y>=0&&y<M&&map[x][y]!='#')return true;
	return false;
}
int flag;
void dfs1(int x,int y,int temp,int face)//1朝左，2朝上，3朝右，4朝下
{
	if(flag)return;
	if(map[x][y]=='E')
	{
		ans1=temp;
		flag=1;
		return ;
	}
	if(face==1)
	{
		if(judge(x+1,y))dfs1(x+1,y,temp+1,4);//下
		if(judge(x,y-1))dfs1(x,y-1,temp+1,1);//左
		if(judge(x-1,y))dfs1(x-1,y,temp+1,2);//上
		if(judge(x,y+1))dfs1(x,y+1,temp+1,3);//右
	}
	else if(face==2)
	{
		if(judge(x,y-1))dfs1(x,y-1,temp+1,1);//左
		if(judge(x-1,y))dfs1(x-1,y,temp+1,2);//上
		if(judge(x,y+1))dfs1(x,y+1,temp+1,3);//右
		if(judge(x+1,y))dfs1(x+1,y,temp+1,4);//下
	}
	else if(face==3)
	{
		if(judge(x-1,y))dfs1(x-1,y,temp+1,2);//上
		if(judge(x,y+1))dfs1(x,y+1,temp+1,3);//右
		if(judge(x+1,y))dfs1(x+1,y,temp+1,4);//下
		if(judge(x,y-1))dfs1(x,y-1,temp+1,1);//左
	}
	else if(face==4)
	{
		if(judge(x,y+1))dfs1(x,y+1,temp+1,3);//右
		if(judge(x+1,y))dfs1(x+1,y,temp+1,4);//下
		if(judge(x,y-1))dfs1(x,y-1,temp+1,1);//左
		if(judge(x-1,y))dfs1(x-1,y,temp+1,2);//上
	}
}
void dfs2(int x,int y,int temp,int face)
{
	if(flag)return;
	if(map[x][y]=='E')
	{
		ans2=temp;
		flag=1;
		return ;
	}
	if(face==1)
	{
		if(judge(x-1,y))dfs2(x-1,y,temp+1,2);//上
		if(judge(x,y-1))dfs2(x,y-1,temp+1,1);//左
		if(judge(x+1,y))dfs2(x+1,y,temp+1,4);//下
		if(judge(x,y+1))dfs2(x,y+1,temp+1,3);//右
	}
	else if(face==2)
	{
		if(judge(x,y+1))dfs2(x,y+1,temp+1,3);//右
		if(judge(x-1,y))dfs2(x-1,y,temp+1,2);//上
		if(judge(x,y-1))dfs2(x,y-1,temp+1,1);//左
		if(judge(x+1,y))dfs2(x+1,y,temp+1,4);//下
	}
	else if(face==3)
	{
		if(judge(x+1,y))dfs2(x+1,y,temp+1,4);//下
		if(judge(x,y+1))dfs2(x,y+1,temp+1,3);//右
		if(judge(x-1,y))dfs2(x-1,y,temp+1,2);//上
		if(judge(x,y-1))dfs2(x,y-1,temp+1,1);//左
	}
	else if(face==4)
	{
		if(judge(x,y-1))dfs2(x,y-1,temp+1,1);//左
		if(judge(x+1,y))dfs2(x+1,y,temp+1,4);//下
		if(judge(x,y+1))dfs2(x,y+1,temp+1,3);//右
		if(judge(x-1,y))dfs2(x-1,y,temp+1,2);//上
	}
}
struct node
{
	int x,y;
	int temp;
};
int dxx[]={0,0,1,-1};
int dyy[]={1,-1,0,0};
int visit[45][45];
int bfs(int x,int y)
{
	queue<node> Q;
	while(!Q.empty())Q.pop();
	node now,tmp;
	now.x=x;
	now.y=y;
	now.temp=1;
	Q.push(now);
	visit[x][y]=1;
	while(!Q.empty())
	{
		now=Q.front();
		Q.pop();
		if(map[now.x][now.y]=='E')
		{
			return now.temp;
		}
		for(int i=0;i<4;i++)
		{
			int tx=now.x+dxx[i];
			int ty=now.y+dyy[i];
			if(judge(tx,ty)&&(!visit[tx][ty]))
			{
				tmp.x=tx;
				tmp.y=ty;
				tmp.temp=now.temp+1;
				visit[tx][ty]=1;
				Q.push(tmp);
			}
		}
	}
	return 0;
}
int main()
{
	int T;
	//scanf("%d",&T);
	cin>>T;
	while(T--)
	{
		int sx,sy;
		//scanf("%d %d",&M,&N);
		cin>>M>>N;
		for(int i=0;i<N;i++)
		{
			//scanf("%s",map[i]);
			cin>>map[i];
			for(int j=0;j<M;j++)
				if(map[i][j]=='S')sx=i,sy=j;
		}
		ans1=0,flag=0;
		dfs1(sx,sy,1,1);//起点只有一个方向可走
		ans2=0,flag=0;
		dfs2(sx,sy,1,1);
		memset(visit,0,sizeof(visit));
		int ans3=bfs(sx,sy);
		printf("%d %d %d\n",ans1,ans2,ans3);
	}
	return 0;
}