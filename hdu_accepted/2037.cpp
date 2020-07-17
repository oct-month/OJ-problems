#include<iostream>
#include<algorithm>
using namespace std;
struct ans
{
	int its;
	int ite;
};
ans a[100];
struct Rule
{
	bool operator()(const ans a,const ans b)
	{
		return a.ite>b.ite;
	}
};
int main()
{
	int N,m,n;
	while(cin>>N&&N)
	{
		m=0;
		n=0;
		for(int i=0;i<N;i++)
			cin>>a[i].its>>a[i].ite;
		sort(a,a+N,Rule());//按结束时间有序
		for(int i=N-1;i>=0;i--)//每次优先选择结束时间早的节目，然后更新开始时间
		{
			if(a[i].its>=n)
			{
				m++;
				n=a[i].ite;//更新开始时间
			}
		}
		cout<<m<<endl;
	}
	return 0;
}