#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int T,n,a[100020],begin,end,sum,max,temp;
	cin>>T;
	for(int cas=1;cas<=T;cas++)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)cin>>a[i];
		begin=1;
		sum=0;
		max=-1001;
		temp=1;
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
			if(sum>max)
			{
				max=sum;
				begin=temp;
				end=i;
			}
			if(sum<0)
			{
				sum=0;
				temp=i+1;
			}
		}
		if(cas<T)cout<<"Case "<<cas<<":\n"<<max<<' '<<begin<<' '<<end<<'\n'<<endl;
		else cout<<"Case "<<cas<<":\n"<<max<<' '<<begin<<' '<<end<<endl;
	}
}
