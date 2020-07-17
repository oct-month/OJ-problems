#include<iostream>
using namespace std;
int pre[10000001],sum[10000001];
int maxx;
int findpre(int e)//找到树中最上面的节点
{
	int t1,t2=e;
	while(e!=pre[e])e=pre[e];
	while(pre[t2]!=e)//使下面的节点直接指向根
    {
        t1=pre[t2];
        pre[t2]=e;
        t2=t1;
    }
	return e;
}
void change(int a,int b)
{
	int t1=findpre(a);
	int t2=findpre(b);
	if(t1!=t2)
	{
		pre[t2]=t1;//将两棵树连在一起
		sum[t1]+=sum[t2];
		if(sum[t1]>maxx)maxx=sum[t1];
	}
}
int main()
{
	int n,x,y;
	while(cin>>n)
	{
		if(n==0)
		{
			cout<<1<<endl;
			continue;
		}
		for(int j=1;j<10000001;j++)//初始化
		{
			pre[j]=j;//初始化为连通分量上的根
			sum[j]=1;//初始的节点数为1
		}
		maxx=1;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			change(x,y);
		}
		cout<<maxx<<endl;
	}
	return 0;
}