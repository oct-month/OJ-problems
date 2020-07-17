//http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=4130
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
char light[200005];
int n,m;
int judge(int e)
{
    int i=0,num=0;
    while(i<n)
    {
        while(i<n&&light[i]!='1')i++;//找到第一个点
        if(i==n)break;//未找到
        i+=e;
        num++;//当间隔为e 时需要Num次
    }
    if(num>m)return -1;//次数多了，e需要变大
    return 1;//次数少了或刚好，e或许可以更小
}
int find_num(int a,int b)//从a~b区间二分
{
    int mid=(a+b)/2;
    while(a<b)
    {
        int tap=judge(mid);
        if(tap==-1)a=mid+1;
        else if(tap==1)b=mid;
        mid=(a+b)/2;
    }
    return mid;
}
int main()
{
	int T,num;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d\n",&n,&m);
		gets(light);
		num=find_num(1,ceil(n/float(m)));
        printf("%d\n",num);
	}
	return 0;
}