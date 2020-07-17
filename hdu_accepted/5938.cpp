#include<iostream>
#include<cstring>
using namespace std;
long long max(long long a,long long b)
{
	return a>b?a:b;
}
long long min(long long a,long long b)
{
	return a<b?a:b;
}
char s[30];
long long d[30],f[30],n;
long long num(int x,int y)//把字符串变成数字
{
    long long sum=0;
    for(int i=x;i<=y;i++)sum=sum*10+s[i]-'0';
    return sum;
}
int main()
{
    int T,cas=1;
	cin>>T;
    while(T--)
    {
        memset(d,0,sizeof d);
        for(int i=0;i<30;i++)f[i]=__LONG_LONG_MAX__;
        scanf("%s",s);
        n=strlen(s);
        for(int i=0;i<n-3;i++)//以i为断点，左边求加的最大
        {
            for(int j=0;j<i;j++)d[i]=max(d[i],num(0,j)+num(j+1,i));
        }
        for(int i=n-1;i>=2;i--)//右边求乘除的最小
        {
            for(int j=i;j<=n-1;j++)
            {
                for(int k=j+1;k<n-1;k++)f[i]=min(f[i],num(i,j)*num(j+1,k)/num(k+1,n-1));
            }
        }
        long long ans=-__LONG_LONG_MAX__;
        for(int i=1;i<n-3;i++)ans=max(ans,d[i]-f[i+1]);
        printf("Case #%d: %lld\n",cas++,ans);
    }
    return 0;
}