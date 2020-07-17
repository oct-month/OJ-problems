#include<iostream>
#include<cstring>
using namespace std;
int cas,n,m;
int sg[1010];
int msg(int len)
{
	if(len<m)return sg[len]=0;
	if(sg[len]!=-1)return sg[len];
	bool visit[1010]={0};
	for(int i=0;len-i-m>=0;i++)
	{
		visit[msg(i)^msg(len-i-m)]=1;
	}
	for(int i=0;i<1010;i++)
	{
		if(!visit[i])return sg[len]=i;
	}
}
int main()
{
	cin>>cas;
	for(int t=1;t<=cas;t++)
	{
		cin>>n>>m;
		if(m>n)printf("Case #%d: abcdxyzk\n",t);
		else
		{
			memset(sg,-1,sizeof(sg));
			if(!msg(n-m))printf("Case #%d: aekdycoin\n",t);
			else printf("Case #%d: abcdxyzk\n",t);
		}
	}
	return 0;
}
