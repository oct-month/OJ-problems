#include<iostream>
using namespace std;
int pre[1001];
int findroot(int v)
{
	int e=v,r;
	while(v!=pre[v])v=pre[v];
	while(e!=v)
	{
		r=pre[e];
		pre[e]=v;
		e=r;
	}
	return v;
}
void change(int x,int y)
{
	int t1=findroot(x);
	int t2=findroot(y);
	pre[t2]=t1;
}
int sum(int N)//计算有多少个根，并减一
{
	int num=0;
	for(int i=1;i<=N;i++)if(pre[i]==i)num++;
	return num-1;
}
int main()
{
	int M,N,x,y;
	while(cin>>N&&N)
	{
		cin>>M;
		for(int i=1;i<=N;i++)pre[i]=i;
		for(int i=0;i<M;i++)
		{
			cin>>x>>y;
			change(x,y);
		}
		cout<<sum(N)<<endl;
	}
	return 0;
}