#include<iostream>
#include<cstring>
#include<set>
using namespace std;
set<int> son[1500];
int dp[2][1501];
int min(int a,int b)
{
	return a<b?a:b;
}
void dfs(int v)
{
	while(!son[v].empty())
	{
		int tap=*son[v].begin();
		son[v].erase(son[v].begin());
		dfs(tap);
		dp[0][v]+=dp[1][tap];
		dp[1][v]+=min(dp[0][tap],dp[1][tap]);
	}
}
int bingc[1501];
void bing(int a,int b)
{
	int rot=b;
	while(bingc[rot]!=rot)rot=bingc[rot];
	bingc[a]=rot;
	bingc[b]=rot;
}
int main()
{
	int point_num;
	while(~scanf("%d",&point_num))
	{
		for(int i=0;i<point_num;i++)bingc[i]=i;
		for(int i=0;i<point_num;i++)
		{
			int h,n,t;
			char e;
			scanf("%d",&h);
			e=getchar();
			e=getchar();
			scanf("%d",&n);
			e=getchar();
			//cin>>h>>e>>e>>n>>e;
			while(n--)
			{
				scanf(" %d",&t);
				//cin>>t;
				son[h].insert(t);
				bing(t,h);
			}
		}
		memset(dp[0],0,sizeof(dp[0]));
		for(int i=0;i<point_num;i++)dp[1][i]=1;
		int root=0;
		while(bingc[root]!=root)root=bingc[root];
		dfs(root);
		printf("%d\n",min(dp[0][root],dp[1][root]));
		//cout<<min(dp[0][root],dp[1][root])<<endl;
	}
	return 0;
}