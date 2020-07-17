#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define lowbit(i) (i&(-i))
vector<vector<int> > Edge(100001);
int n,m;
int tree[100001];
int area[100001];
int C[100001];
bool app[100001];
void update(int i,int e)
{
	while(i<=n)
	{
		C[i]+=e;
		i+=lowbit(i);
	}
}
int qsum(int i)
{
	int tap=0;
	while(i>=1)
	{
		tap+=C[i];
		i-=lowbit(i);
	}
	return tap;
}
int key;
void dfs(int node)//对叉重新编码并划定范围,转化为树状数组的问题
{
	tree[node]=key;//左范围，同时也代表 node 被转码成 key
	for(int i=0;i<Edge[node].size();i++)
	{
		key++;
		dfs(Edge[node][i]);
	}
	area[node]=key;//右范围
}
int main()
{
	while(~scanf("%d",&n))
    {
		Edge.clear();
		memset(C,0,sizeof(C));
		memset(app,0,sizeof(app));
		int a,b;
		for(int i=0;i<n-1;i++)
		{
			scanf("%d %d",&a,&b);
			Edge[a].push_back(b);
		}
		for(int i=1;i<=n;i++)update(i,1);
		key=1;
		dfs(1);
		scanf("%d",&m);
		while(m--)
		{
			char action;
            int date;
            scanf("\n%c %d",&action,&date);
			if(action=='Q')
			{
				printf("%d\n",qsum(area[date])-qsum(tree[date]-1));
			}
			else
			{
				if(app[date])
				{
					update(tree[date],1);
					app[date]=false;
				}
				else 
				{
					update(tree[date],-1);
					app[date]=true;
				}
			}
		}
	}
	return 0;
}