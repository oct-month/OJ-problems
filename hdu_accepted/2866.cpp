#include<iostream>
#include<cmath>
using namespace std;
bool prime[1000005];
int en[1000005];
bool judge(int e)
{
	int h=sqrt(e);
	if(h*h==e)return true;
	return false;
}
void init()
{
	for(int i=2;i<1000005;i++)prime[i]=true;//初始化所有数都是质数
	prime[0]=prime[1]=false;
	en[0]=en[1]=0;
	int cnt=0;
	for(int i=2;i<1000005;i++)
	{
		if(prime[i])
		{
			int tap=12*i-3;
			if(judge(tap))cnt++;
			for(int j=2*i;j<1000005;j+=i)
				prime[j]=false;
		}
		en[i]=cnt;
	}
}
int main()
{
	int L;
	init();
	while(cin>>L)
	{
		if(en[L]==0)cout<<"No Special Prime!"<<endl;
		else cout<<en[L]<<endl;
	}
	return 0;
}
//https://blog.csdn.net/codeswarrior/article/details/81279067