#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
LL a[1010],b[1010];
LL ex_gcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    LL gcd=ex_gcd(b,a%b,x,y);
    LL temp=x;
    x=y,y=temp-a/b*y;
    return gcd;
}
LL modeqset(LL a[],LL b[],LL m)
{
    LL i,d,c,x,y,t;
    for(i=1;i<m;i++)
    {
        c=b[i]-b[i-1];
        d=ex_gcd(a[i-1],a[i],x,y);
        if(c%d)return -1;
        t=a[i]/d;
        x=(x*(c/d)%t+t)%t;
        b[i]=x*a[i-1]+b[i-1];
        a[i]=a[i-1]*(a[i]/d);
        b[i]%=a[i];
    }
    return b[m-1];
}
int main()
{
    LL m,res;
    while(~scanf("%lld",&m))
    {
        for(LL i=0;i<m;i++)scanf("%lld %lld",a+i,b+i);
        res=modeqset(a,b,m);
        printf("%lld\n",res);
    }
    return 0;
}
