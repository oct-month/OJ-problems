#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
LL c[55][55];
void getc()
{
	memset(c,0,sizeof(c));
	for(int i=0;i<55;i++)c[i][0]=1;
	for(int i=1;i<55;i++)
		for(int j=1;j<55;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
}
void jvc(LL (*a)[55],LL (*b)[55],int x,int M)
{
	LL tap[55][55];
	memset(tap,0,sizeof(tap));
	for(int i=0;i<=x;i++)
		for(int j=0;j<=x;j++)
			for(int k=0;k<=x;k++)
				tap[i][j]=(tap[i][j]+(a[i][k]*b[k][j])%M)%M;
	for(int i=0;i<=x;i++)
		for(int j=0;j<=x;j++)
			a[i][j]=tap[i][j];
}
void jvf(LL (*a)[55],int N,int x,int M)
{
	LL ret[55][55];
	memset(ret,0,sizeof(ret));
	for(int i=0;i<55;i++)ret[i][i]=1;
	while(N)
	{
		if(N%2)jvc(ret,a,x,M);
		jvc(a,a,x,M);
		N/=2;
	}
	for(int i=0;i<=x;i++)
		for(int j=0;j<=x;j++)
			a[i][j]=ret[i][j]%M;
}
int main()
{
	int N,x,M;
	LL ans[55][55];
	getc();
	while(cin>>N>>x>>M)
	{
		if(N<0&&x<0&&M<0)break;
		memset(ans,0,sizeof(ans));
		for(int i=0;i<=x;i++)
			for(int j=0;j<=i;j++)
				ans[i][j]=(c[i][j]*x)%M;
		ans[x+1][x]=ans[x+1][x+1]=1;
		jvf(ans,N,x+1,M);
		LL sum=0;
		for(int i=0;i<=x;i++)sum=(sum+(ans[x+1][i]*x)%M)%M;
		cout<<sum%M<<endl;
	}
	return 0;
}