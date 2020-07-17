#include<iostream>
#include<cstring>
using namespace std;
int f[110];//限制取
int sg[10010];//sg函数数组
bool visit[10010];
int sgtap[110];
char edn[110];
void sg_do(int n,int k)
{
	memset(sg,0,sizeof(sg));
	for(int i=1;i<=n;i++)
	{
		memset(visit,0,sizeof(visit));
		for(int j=1;j<=k;j++)
		{
			if(i-f[j]>=0&&j<=k)//对于每个 i 能到达的点 
			{
				visit[sg[i-f[j]]]=true;
			}
			for(int j=0;j<=n;j++)//sg函数运算（找最小非负整数）
				if(!visit[j])
				{
					sg[i]=j;
					break;
				}
		}
	}
}
int main()
{
	int k,m,l,ans;
	while(cin>>k&&k)
	{
		for(int i=1;i<=k;i++)cin>>f[i];
		sg_do(10000,k);//sg函数预处理
		cin>>m;
		for(int t=0;t<m;t++)
		{
			cin>>l;
			for(int i=1;i<=l;i++)
			{
				cin>>ans;
				sgtap[i]=sg[ans];
			}
			for(int i=2;i<=l;i++)
			{
				sgtap[i]=sgtap[i]^sgtap[i-1];
			}
			if(sgtap[l])edn[t]='W';
			else edn[t]='L';
		}
		edn[m]='\0';
		cout<<edn<<endl;
	}
}
