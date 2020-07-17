#include<iostream>
#include<cstring>
using namespace std;
int weight[105];
int dp[2][100001];
int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int N,n;
	while(cin>>N>>n)
	{
		int a,b,h;
		h=0;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			for(int j=1;a!=0;j*=2)
			{
				if(a>=j)
				{
					h++;
					a-=j;
					weight[h]=j*b;
				}
				else 
				{
					h++;
					weight[h]=a*b;
					break;
				}
			}
		}
		for(int i=0;i<2;i++)
			for(int j=0;j<=N;j++)
				dp[i][j]=N;
		for(int i=1;i<=h;i++)
		{
			int e=i%2;
			for(int j=1;j<=N;j++)
			{
				if(weight[i]<=j)
				{
					if(dp[!e][j-weight[i]]-weight[i]>=0)dp[e][j]=min(dp[!e][j-weight[i]]-weight[i],dp[!e][j]);
				}
				else dp[e][j]=dp[!e][j];
			}
		}
		cout<<N-dp[h%2][N]<<endl;
	}
	return 0;
}