#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct ans
{
	int data;//截止时间
	int score;//分数
};
struct Rule
{
	bool operator()(const ans &a,const ans &b)
	{
		return a.score<b.score;
	}
};
ans a[1000];
int t[1001];//时间数组，0表示当天未被使用
int findata(int e)//找到空闲的时间
{
	while(e&&t[e])e--;
	return e;
}
int main()
{
	int T,n;
	int x,y;
	cin>>T;
	while(T--)
	{
		y=0;
		memset(t,0,sizeof(t));
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i].data;
		for(int i=0;i<n;i++)cin>>a[i].score;
		sort(a,a+n,Rule());//按分数有序，分数大的优先完成，完成时间尽量靠后
		for(int i=n-1;i>=0;i--)
		{
			x=findata(a[i].data);
			if(x)t[x]=1;
			else y+=a[i].score;
		}
		cout<<y<<endl;
	}
	return 0;
}