#include<iostream>
#include<set>
using namespace std;
int bingc[102];
struct lu
{
	int a;
	int b;
	int value;
};
struct Rule
{
	bool operator()(const lu &a,const lu &b)
	{
		return a.value<b.value;
	}
};
multiset<lu,Rule> L;
int endv,endif;
int lian(int a,int b)
{
	int at=a,bt=b,at2,bt2;
	while(bingc[a]!=a)a=bingc[a];
	while(bingc[b]!=b)b=bingc[b];
	while(bingc[at]!=at)
	{
		at2=bingc[at];
		bingc[at]=a;
		at=at2;
	}
	while(bingc[bt]!=bt)
	{
		bt2=bingc[bt];
		bingc[bt]=b;
		bt=bt2;
	}
	if(a==b)return 1;
	else return 0;
}
void bing(int a,int b)
{
	while(bingc[a]!=a)a=bingc[a];
	while(bingc[b]!=b)b=bingc[b];
	bingc[b]=a;
}
void dfs()
{
	lu tap;
	multiset<lu,Rule>::iterator I;
	while(!L.empty())
	{
		I=L.begin();
		tap=*I;
		if(!lian(tap.a,tap.b))
		{
			endv+=tap.value;
			endif++;
			bing(tap.a,tap.b);
		}
		L.erase(I);
	}
}
int main()
{
	int N,M;
	lu aa;
	while(cin>>N>>M&&N)
	{
		endv=0;
		endif=1;
		for(int i=1;i<=M;i++)bingc[i]=i;
		for(int i=1;i<=N;i++)
		{
			cin>>aa.a>>aa.b>>aa.value;			
			L.insert(aa);
		}
		dfs();
		if(endif==M)cout<<endv<<endl;
		else cout<<'?'<<endl;
	}
	return 0;
}