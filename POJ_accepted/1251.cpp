#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
struct node
{
	int a,b;
	int v;
};
struct rule
{
	bool operator()(const node &a,const node &b)
	{
		return a.v<b.v;
	}
};
int N;
multiset<node,rule> H;
int bingc[30];
bool judge(int a,int b)
{
	while(a!=bingc[a])a=bingc[a];
	while(b!=bingc[b])b=bingc[b];
	if(a==b)return true;
	return false;
}
void bing(int a,int b)
{
	int tap=a;
	while(a!=bingc[a])a=bingc[a];
	while(b!=bingc[b])b=bingc[b];
	bingc[b]=a;
	bingc[tap]=a;
}
int sum;
void djst()
{
	node tap;
	while(!H.empty())
	{
		tap=*H.begin();
		H.erase(H.begin());
		if(!judge(tap.a,tap.b))
		{
			sum+=tap.v;
			bing(tap.a,tap.b);
		}
	}
}
int main()
{
	while(~scanf("%d",&N)&&N)
	{
		char ths,that;
		int num,valu;
		node now;
		for(int i=1;i<=N-1;i++)
		{
			scanf("\n%c %d",&ths,&num);
			while(num--)
			{
				scanf(" %c %d",&that,&valu);
				now={ths-'A',that-'A',valu};
				H.insert(now);
			}
		}
		for(int i=0;i<N;i++)bingc[i]=i;
		sum=0;
		djst();
		printf("%d\n",sum);
	}
	return 0;
}