#include<iostream>
using namespace std;
typedef long long LL;
LL cf(int a,int b,int m)
{
	LL tap=1;
	while(b)
	{
		if(b%2)tap=(tap*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return tap;
}
int main()
{
	int T,m,H;
	cin>>T;
	while(T--)
	{
		cin>>m>>H;
		int a,b;
		LL sum=0;
		while(H--)
		{
			cin>>a>>b;
			sum+=cf(a%m,b,m);
		}
		cout<<sum%m<<endl;
	}
	return 0;
}