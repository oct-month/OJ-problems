#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
char ans[20][20];
LL n,k;
LL num;
bool vj[20];
void dfs(LL a,LL b)
{
	if(b>=k)
	{
		num++;
		return;
	}
	if(a>n)return;
	for(LL i=a;i<n;i++)
		for(LL j=0;j<n;j++)
			if(vj[j]==false&&ans[i][j]=='#')
			{
				vj[j]=true;
				dfs(i+1,b+1);
				vj[j]=false;
			}
}
int main()
{
	while(cin>>n>>k&&n!=-1)
	{
		for(LL i=0;i<n;i++)
			cin>>ans[i];
		memset(vj,0,sizeof(vj));
		num=0;
		dfs(0,0);
		cout<<num<<endl;
	}
	return 0;
}