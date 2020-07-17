#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
int my_prime[5000],cot;
bool prime[1000001];
void init()
{
	cot=0;
	memset(prime,0,sizeof(prime));//false表示是质数
	prime[0]=prime[1]=true;
	for(LL i=2;i<47000;i++)
	{
		if(!prime[i])
		{
			my_prime[cot++]=i;
			for(LL j=i*i;j<47000;j+=i)
				prime[j]=true;
		}
	}
}
struct node
{
	int sta;
	int edn;
	int v;
};
bool rule(node a,node b)
{
	if(a.v==b.v)return a.edn<b.edn;
	return a.v<b.v;
}
node ans[1000001];
int noot;
int esai(int a,int b)
{
	if(a>=b)return 0;
	noot=0;
	memset(prime,0,sizeof(prime));
	int cnt=0;
	for(int i=0;i<cot;i++)
	{
		for(LL j=a/my_prime[i];j*my_prime[i]<=b;j++)
		{
			LL tap=j*my_prime[i]-a;
			if(tap>=0&&j>=2)prime[tap]=1;
		}
	}
	for(int i=0;i<=b-a;i++)
	{
		if(!prime[i])
		{
			ans[noot++].edn=i+a;
		}
	}
	if(noot<2)return 0;
	for(int i=1;i<noot;i++)
	{
		ans[i].sta=ans[i-1].edn;
		ans[i].v=ans[i].edn-ans[i].sta;
	}
	sort(ans+1,ans+noot,rule);
	for(int i=noot-2;i>=1;i--)
	{
		if(ans[noot-1].v==ans[i].v)ans[noot-1]=ans[i];
		else break;
	}
	return 1;
}
int main()
{
	init();//获取1~sqrt(INT_MAX) 之间的质数
	int a,b;
	while(cin>>a>>b)
	{
		if(a==1)a++;
		if(esai(a,b))printf("%d,%d are closest, %d,%d are most distant.\n",ans[1].sta,ans[1].edn,ans[noot-1].sta,ans[noot-1].edn);
		else printf("There are no adjacent primes.\n");
	}
	return 0;
}