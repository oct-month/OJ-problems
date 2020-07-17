#include<iostream>
#include<cstdio>
using namespace std;
int ex_gcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;//最小公约数
	}
	int gcd=ex_gcd(b,a%b,x,y);
	int temp=x;
	x=y,y=temp-a/b*y;
	return gcd;
}
int abs(int e)
{
	return e>0?e:-e;
}
int main()
{
	int a,b,d,x,y;
	while(cin>>a>>b>>d&&a+b+d)
	{
		int gcd=ex_gcd(a,b,x,y);
		a/=gcd,b/=gcd,d/=gcd;
		int x1=x*d;
		x1=(x1%b+b)%b;//x1不停的加b/gcd直到为正
		int y1=(d-a*x1)/b;//a*x1+b*y1=d
		y1=abs(y1);
		int y2=y*d;
		y2=(y2%a+a)%a;
		int x2=(d-b*y2)/a;
		x2=abs(x2);
		if(x1+y1<x2+y2)cout<<x1<<' '<<y1<<endl;
		else cout<<x2<<' '<<y2<<endl;
	}
	return 0;
}
//gcd(a,b)=gcd(b,a%b)
//ax+by=gcd(a,b)
//x1=y2
//y1=x2-a/b*y2
//x=x0+b/gcd*t   #t为任意整数
//y=y-a/gcd*t    #t为任意整数
//https://baike.baidu.com/item/%E6%89%A9%E5%B1%95%E6%AC%A7%E5%87%A0%E9%87%8C%E5%BE%B7%E7%AE%97%E6%B3%95/1053275?fr=aladdin
//https://blog.csdn.net/qq_41292370/article/details/81106888