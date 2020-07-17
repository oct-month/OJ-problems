#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
LL ex_gcd(LL a,LL b,LL &x,LL &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	LL md=ex_gcd(b,a%b,x,y);
	LL temp=x;
	x=y,y=temp-a/b*y;
    return md;
}
int main()
{
    LL A,B,C,k,x,y;
    while(~scanf("%lld %lld %lld %lld",&A,&B,&C,&k)&&A+B+C+k)
    { 
        LL a=C,b=1LL<<k,c=B-A;
        LL gcd=ex_gcd(a,b,x,y);
        if(c%gcd)
        {
            printf("FOREVER\n");
            continue;
        }
        a/=gcd,c/=gcd,b/=gcd;
        x*=c;
        x=(x%b+b)%b;
        printf("%lld\n",x);
    }
	return 0;
}
//https://blog.csdn.net/qq_22902423/article/details/50569835
