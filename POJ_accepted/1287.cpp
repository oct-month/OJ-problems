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
int bingc[51];
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
int map[51][51];
int main()
{
	int p;
    while(~scanf("%d",&N)&&N)
    {
        scanf("%d",&p);
        for(int i=0;i<=N;i++)
            for(int j=0;j<=N;j++)
                map[i][j]=0xfffffff;
        int a,b,v;
        while(p--)
        {
            scanf("%d %d %d",&a,&b,&v);
            map[a][b]=map[b][a]=min(map[a][b],v);
        }
        for(int i=1;i<=N;i++)
            for(int j=i+1;j<=N;j++)
                if(map[i][j]<0xfffffff)H.insert({i,j,map[i][j]});
        sum=0;
        for(int i=1;i<=N;i++)bingc[i]=i;
        djst();
        printf("%d\n",sum);
    }
	return 0;
}