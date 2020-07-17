#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define lowbit(i) (i&(-i))
int C[32002],num[32002];
void update(int *array,int i,int e)
{
	while(i<=32001)
	{
		array[i]+=e;
		i+=lowbit(i);
	}
}
int qsum(int *array,int n)
{
	int tap=0;
	while(n>0)
	{
		tap+=array[n];
		n-=lowbit(n);
	}
	return tap;
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int x,y;
		memset(C,0,sizeof(C));
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			update(C,x+1,1);//y??????????????
			num[qsum(C,x+1)-1]++;
		}
		for(int i=0;i<n;i++)
			printf("%d\n",*(num+i));
	}
	return 0;
}