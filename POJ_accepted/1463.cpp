#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int dp[2][1501];
int brother[1501];
int son[1501];
int min(int a,int b)
{
	return a<b?a:b;
}
void dfs(int v)
{
	int w=son[v];
	while(w!=-1)
	{
		dfs(w);
		dp[0][v]+=dp[1][w];
		dp[1][v]+=min(dp[0][w],dp[1][w]);
		w=brother[w];
	}
}
int bingc[1501];
void bing(int a,int b)
{
	int rot=b;
	bingc[a]=b;
	while(bingc[rot]!=rot)rot=bingc[rot];
	while(bingc[a]!=rot)
	{
		b=a;
		a=bingc[a];
		bingc[b]=rot;
	}
}
int main()
{
	int point_num;
	while(~scanf("%d",&point_num))
	{
		for(int i=0;i<point_num;i++){bingc[i]=i;dp[1][i]=1;}
		memset(dp[0],0,sizeof(dp[0]));
		memset(brother,-1,sizeof(brother));
		memset(son,-1,sizeof(son));
		for(int i=0;i<point_num;i++)
		{
			int h,n,t;
			scanf("%d:(%d)",&h,&n);
			int m=n;
			for(int j=0;j<n;j++)
			{
				scanf(" %d",&t);
				if(j)brother[m]=t;
				else son[h]=t;
				m=t;
				bing(t,h);
			}
		}
		int root=0;
		while(bingc[root]!=root)root=bingc[root];
		dfs(root);
		printf("%d\n",min(dp[0][root],dp[1][root]));
	}
	return 0;
}