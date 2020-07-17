#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int map[1001][1001];
int djs[1001];
int M,N;
int visit[1001];
void dijs()
{
	int k=0,min;
	for(int i=1;i<=N;i++)djs[i]=map[1][i],visit[i]=0;
	for(int i=1;i<N;i++)
	{
		min=0xfffffff;
		for(int j=1;j<=N;j++)
			if(!visit[j]&&djs[j]<min)min=djs[j],k=j;//找到最短边
		visit[k]=1;//每次将最短边纳入
		for(int j=1;j<=N;j++)
			if(!visit[j]&&djs[k]+map[k][j]<djs[j])djs[j]=djs[k]+map[k][j];
	}
}
int main()
{
	while(~scanf("%d %d",&M,&N))
	{
		int a,b,v;
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				map[i][j]=0xfffffff;
		while(M--)
		{
			scanf("%d %d %d",&a,&b,&v);
			map[b][a]=map[a][b]=min(map[a][b],v);
		}
		dijs();
		printf("%d\n",djs[N]);
	}
	return 0;
}