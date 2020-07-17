#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[2][12881];
int weight[3500],value[3500];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
			scanf("%d %d",weight+i,value+i);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				int tap=i%2;
				if(weight[i]<=j)
				{
					dp[tap][j]=max(dp[!tap][j-weight[i]]+value[i],dp[!tap][j]);
				}
				else dp[tap][j]=dp[!tap][j];
			}
		cout<<dp[n%2][m]<<endl;
	}
	return 0;
}