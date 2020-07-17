#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int ans[1000001];
int maxtp[1000001];
int dp[1000001];
int n,m;
int max(int a,int b)
{
	return a>b?a:b;
}
int dps()
{
	int tmp;
	for(int i=1;i<=n;i++)//i个子序列
	{
		tmp=-0xfffffff;
		for(int j=i;j<=m;j++)//j个数
		{
			/* maxtp[j-1]表示当取i-1个子序列时，前j-1个数所能取到的最大值 */
			dp[j]=max(maxtp[j-1]+ans[j],dp[j-1]+ans[j]);//第j个数要么不与j-1合并，要么与j-1合并
			maxtp[j-1]=tmp;//更新maxtp[]为取i个子序列时的情况
			tmp=max(tmp,dp[j]);
		}
	}
	return tmp;
}
int main()
{
	while(cin>>n)
	{
		cin>>m;
		memset(maxtp,0,sizeof(maxtp));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=m;i++)scanf(" %d",ans+i);
		cout<<dps()<<endl;
	}
	return 0;
}