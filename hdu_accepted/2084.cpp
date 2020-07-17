#include<iostream>
using namespace std;
int ans[101][101];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int N,n,v;
	cin>>N;
	for(int u=0;u<N;u++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				cin>>ans[i][j];//下三角矩阵存储
		for(int i=n-1;i>0;i--)
		{
			for(int j=1;j<=i;j++)
			{	
				ans[i][j]+=max(ans[i+1][j],ans[i+1][j+1]);//由下至上DP
			}
		}
		cout<<ans[1][1]<<endl;
	}
	return 0;
}