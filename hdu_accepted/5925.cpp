#include<iostream>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
int xi[201],yi[201];//坏点坐标
set<int> X,Y;
set<int>::iterator I,J;
LL ans[410][410];//压缩后的矩阵
LL ansdata1[410];
int xlong,ylong;//压缩矩阵的长和宽
int aq,bq;
LL hao[400];
int numend;
void change(int a,int b)//根据坏点坐标更新矩阵
{
	I=X.begin();
	J=Y.begin();
	int xa=0,ya=0;
	while(*I!=a)
	{
		I++;
		xa++;
	}
	while(*J!=b)
	{
		J++;
		ya++;
	}
	ans[xa][ya]=0;
}
int find(int a)//从a行开始查找好椰子
{
	for(int i=a;i<=xlong;i++)
		for(int j=1;j<=ylong;j++)
			if(ans[i][j])
			{
				aq=i;
				bq=j;
				return 1;
			}
	return 0;
}
void color(int x,int y)//遍历
{
	if(x<=0||y<=0||x>xlong||y>ylong)return ;
	if(ans[x][y])
	{
		hao[numend]+=ans[x][y];
		ans[x][y]=0;
		color(x-1,y);
		color(x+1,y);
		color(x,y-1);
		color(x,y+1);
	}
}
int main()
{
	int T,R,C,N;
	cin>>T;
	for(int u=1;u<=T;u++)
	{
		cin>>R>>C>>N;
		for(int i=0;i<N;i++)
		{
			cin>>xi[i]>>yi[i];
			X.insert(xi[i]);
			X.insert(xi[i]-1);
			Y.insert(yi[i]);
			Y.insert(yi[i]-1);
		}
		X.insert(0);
		Y.insert(0);
		X.insert(R);
		Y.insert(C);
		/*离散化矩阵存储*/
		xlong=X.size()-1;
		ylong=Y.size()-1;
		I=J=Y.begin();
		for(int j=1;j<=ylong;j++)
		{
			J++;
			ansdata1[j]=(*J)-(*I);
			I=J;
		}
		I=J=X.begin();
		for(int i=1;i<=xlong;i++)
		{
			J++;
			for(int j=1;j<=ylong;j++)
				ans[i][j]=ansdata1[j]*((*J)-(*I));
			I=J;
		}
		for(int i=0;i<N;i++)
		{
			change(xi[i],yi[i]);
		}
		aq=1;
		memset(hao,0,sizeof(hao));
		numend=0;
		while(find(aq))
		{
			color(aq,bq);
			numend++;
		}
		X.clear();
		Y.clear();
		sort(hao,hao+numend);
		printf("Case #%d:\n%d\n",u,numend);
		for(int i=0;i<numend;i++)
			if(i)printf(" %lld",hao[i]);
			else printf("%lld",hao[i]);
		putchar('\n');
	}
	return 0;
}