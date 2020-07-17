#include<iostream>
using namespace std;
void jvc(int (*a)[10],int (*b)[10],int m)//a*b,结果存放在a中
{
	int tap[10][10]={0};
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<10;k++)
				tap[i][j]+=a[i][k]*b[k][j];
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			a[i][j]=tap[i][j]%m;
}
void jvf(int (*a)[10],int h,int m)//a^h,结果存放在a中
{
	int ret[10][10]={0};
	for(int i=0;i<10;i++)ret[i][i]=1;
	while(h)
	{
		if(h%2)jvc(ret,a,m);
		jvc(a,a,m);
		h/=2;
	}
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			a[i][j]=ret[i][j];
}
int f(int (*a)[10],int x,int m)
{
	if(x<10)return x;
	jvf(a,x-9,m);
	int tap=0;
	for(int i=0;i<10;i++)
		tap+=a[0][i]*(9-i);
	return tap;
}
int main()
{
	int k,m;
	while(~scanf("%d %d",&k,&m))
	{
		int a[10][10]={0};
		for(int i=0;i<10;i++)scanf("%d",a[0]+i);
		for(int i=1;i<=9;i++)a[i][i-1]=1;
		printf("%d\n",f(a,k,m)%m);
	}
	return 0;
}