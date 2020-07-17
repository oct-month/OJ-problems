#include<iostream>
using namespace std;
struct title
{
	int xl,yl;
	int xr,yr;
	int s;
}ans[102];
int abs2(int e)
{
	if(e<0)return -e;
	return e;
}
int main()
{
	int T;
	bool flag1,flag2,flag3;
	while(cin>>T)
	{
		while(T--)
		{
			flag1=false,flag2=false,flag3=false;
			int n,m,num;//n为x，m为y
			cin>>n>>m>>num;
			int sum=0;
			for(int i=1;i<=num;i++)
			{
				cin>>ans[i].xl>>ans[i].yl>>ans[i].xr>>ans[i].yr;
				int tap1=abs2(ans[i].xl-ans[i].xr);
				int tap2=abs2(ans[i].yl-ans[i].yr);
				ans[i].s=tap1*tap2;
				sum+=ans[i].s;
				if(ans[i].xl<0||ans[i].yl<0||ans[i].xr>n||ans[i].yr>m)flag2=true;
				if(ans[i].xr<0||ans[i].yr<0||ans[i].xl>n||ans[i].yl>m)flag2=true;
			}
			if(sum<n*m)flag3=true;
			for(int i=1;i<=num;i++)
			{
				if(flag1)break;
				for(int j=i+1;j<=num;j++)
				{
					if(ans[i].xr<=ans[j].xl||ans[j].xr<=ans[i].xl||ans[i].yr<=ans[j].yl||ans[j].yr<=ans[i].yl)
						continue;
					else flag1=true;
				}
			}
			if(flag1)cout<<"NONDISJOINT"<<endl;
			else if(flag2)cout<<"NONCONTAINED"<<endl;
			else if(flag3)cout<<"NONCOVERING"<<endl;
			else cout<<"OK"<<endl;
		}
	}
	return 0;
}