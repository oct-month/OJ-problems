#include<iostream>
#include<cstdio>
#include<set>
#include<cmath>
using namespace std;
int n;
int bingc[201];
struct node
{
	int x,y;
};
struct load
{
	int i,j;
	double v;
};
struct Rule
{
	bool operator()(const load &a,const load &b)
	{
		return a.v<b.v;
	}
};
node point[201];
multiset<load,Rule> H;
void bing(int a,int b)
{
	int tap=b;
	while(bingc[a]!=a)a=bingc[a];
	while(bingc[b]!=b)b=bingc[b];
	bingc[b]=a;
	bingc[tap]=a;
}
bool judge(int i,int j)
{
	while(bingc[i]!=i)i=bingc[i];
	while(bingc[j]!=j)j=bingc[j];
	if(i==j)return 1;
	return 0;
}
double max(double a,double b)
{
	return a>b?a:b;
}
double make()
{
	double maxm=-1;
	while(!judge(1,2))
	{
		load tap=*H.begin();
		H.erase(H.begin());
		bing(tap.i,tap.j);
		maxm=max(maxm,tap.v);
	}
	H.clear();
	return maxm;
}
int main()
{
	int cas=0;
	while(cin>>n&&n)
	{
		cas++;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&point[i].x,&point[i].y);
			//cin>>point[i].x>>point[i].y;
			bingc[i]=i;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				double tap=sqrt((point[i].x-point[j].x)*(point[i].x-point[j].x)+(point[i].y-point[j].y)*(point[i].y-point[j].y));
				H.insert({i,j,tap});
			}
		printf("Scenario #%d\n",cas);
		printf("Frog Distance = %.3f\n\n",make());//在POJ上double要用%f
		//cout<<make()<<endl;
	}
	return 0;
}