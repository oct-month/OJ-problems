#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
char map[201][201];
int mp[201][201];
struct Node
{
	int x,y;
	int temp;
	Node(int a,int b,int c):x(a),y(b),temp(c){}
};
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main()
{
	int T,N,M,a,b;
	cin>>T;
	while(T--)
	{
		cin>>N>>M;
		for(int i=0;i<N;i++)
			scanf("\n%s",map[i]);
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
			{
				if(map[i][j]=='@'||map[i][j]=='a')mp[i][j]=1;
				else if(map[i][j]=='x')mp[i][j]=2;
				else if(map[i][j]=='r')mp[i][j]=0,a=i,b=j;
				else mp[i][j]=0;
			}
		queue<Node> Q;
		Q.push(Node(a,b,0));
		int ans=0x7fffffff;
		while(!Q.empty())
		{
			Node tap=Q.front();
			Q.pop();
			if(map[tap.x][tap.y]=='a')
			{
				ans=min(ans,tap.temp);
				//break;
			}
			if(map[tap.x][tap.y]=='x'&&mp[tap.x][tap.y]==1)//守卫被干掉了,还在原位置
			{
				Q.push(Node(tap.x,tap.y,tap.temp+1));
				mp[tap.x][tap.y]=0;
			}
			else
			{
				for(int i=0;i<4;i++)
				{
					int tx=tap.x+dx[i];
					int ty=tap.y+dy[i];
					if(tx>=0&&tx<N&&ty>=0&&ty<M&&mp[tx][ty])//被走过的点都被置为0
					{
						if(map[tx][ty]=='x'&&mp[tx][ty]==2)//如果守卫还未被干掉，不移动
						{
							Q.push(Node(tx,ty,tap.temp+1));
							mp[tx][ty]=1;
						}
						else if(map[tx][ty]!='x')
						{
							Q.push(Node(tx,ty,tap.temp+mp[tx][ty]));
							mp[tx][ty]=0;
						}
					}
				}
			}
		}
		if(ans<100000000)printf("%d\n",ans);
		else printf("Impossible\n");
	}
	return 0;
}