#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int weight[1001];
int dp[1001][1001];
int max_value;
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n,m;
	while(cin>>n&&n)
	{
		for(int i=1;i<=n;i++)cin>>weight[i];
		cin>>m;
		sort(weight+1,weight+n+1);
		max_value=weight[n];
		n--;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(j-weight[i]>=5)
				{
					dp[i][j]=max(dp[i-1][j-weight[i]]+weight[i],dp[i-1][j]);
				}
				else dp[i][j]=dp[i-1][j];
			}
		}
		int tap=n;
		for(int i=n;i>=1;i--)
			if(dp[i][m]!=dp[i-1][m])
			{
				weight[i]=0xfffffff;
				n--;
			}
		m-=dp[tap][m];
		if(m>=5)m-=max_value;
		else if(m>=max_value)m-=max_value;
		if(n&&m>0)
		{
			sort(weight+1,weight+n+1);
			for(int i=0;i<2;i++)
				for(int j=0;j<=m;j++)
					dp[i][j]=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(weight[i]<=j)
					{
						dp[i][j]=max(dp[i-1][j-weight[i]],dp[i-1][j]);
					}
					else dp[i][j]=dp[i-1][j];
				}
			}
			m=m-dp[n][m];
		}
		cout<<m<<endl;
	}
	return 0;
}