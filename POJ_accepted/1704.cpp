#include<iostream>
#include<algorithm>
using namespace std;
int ans[1005];
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>ans[i];
		sort(ans+1,ans+n+1);
		ans[0]=0;
		int anst=0;
		for(int i=1;i<=n;i++)
		{
			if(n%2==0&&i%2==0)anst^=ans[i]-ans[i-1]-1;//如果n是偶数
			if(n%2==1&&i%2==1)anst^=ans[i]-ans[i-1]-1;//n是奇数
		}
		if(!anst)cout<<"Bob will win"<<endl;
		else cout<<"Georgia will win"<<endl;
	}
	return 0;
}
