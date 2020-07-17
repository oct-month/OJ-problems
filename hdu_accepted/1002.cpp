#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char S1[1020],S2[1020],a[1020],b[1020];
	unsigned int C[1020];
	int len1,len2,lenc,num(0);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(C,0,sizeof(C));
		cin>>S1>>S2;
		len1=strlen(S1);
		len2=strlen(S2);
		lenc=(len1>len2?len1:len2)+1;
		for(int j=0;j<len1;j++)a[len1-j-1]=S1[j]-'0';
		for(int j=0;j<len2;j++)b[len2-j-1]=S2[j]-'0';
		num=0;
		for(int j=0;j<lenc;j++)
		{
			C[j]=a[j]+b[j]+num;
			num=0;
			if(C[j]>=10)
			{
				C[j]-=10;
				num=1;
			}
		}
		if(C[lenc-1]==0)lenc--;
		if(i!=1)cout<<'\n';
		cout<<"Case "<<i<<":\n"<<S1<<" + "<<S2<<" = ";
		for(int j=lenc-1;j>=0;j--)cout<<C[j];
		cout<<endl;
	}
}
