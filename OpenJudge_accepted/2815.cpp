#include<iostream>
#include<cstring>
using namespace std;
int ans[100][100];
int ans2[100][100];
int n,m;
int num,nu;
int max(int a,int b)
{
	return a>b?a:b;
}
void color(int i,int j)
{
	if(ans2[i][j])return;
	int tap=ans[i][j];
	ans2[i][j]=num;
	nu++;
	if((tap&1)==0)color(i,j-1);
	if((tap&2)==0)color(i-1,j);
	if((tap&4)==0)color(i,j+1);
	if((tap&8)==0)color(i+1,j);
}
int main()
{
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>ans[i][j];
		num=0;
		memset(ans2,0,sizeof(ans2));
		int endar=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(ans2[i][j]==0)
				{
					nu=0;
					num++;
					color(i,j);
					endar=max(endar,nu);
				}
		cout<<num<<endl<<endar<<endl;
	}
	return 0;
}