#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const LL INTMAX=1e13;
LL a[501];
void init()
{
    a[1]=6,a[2]=7;
    for(int i=3;i<=500;i++)
    {
        a[i]=a[i-1]+a[i-2];
        if(a[i]>INTMAX)a[i]=INTMAX;
    }
}
char b[3][10]={"none","COFFEE","CHICKEN"};
char ans[501][11];
const char* find(int n,LL k,int v)//返回下标为 K 开始的 v 个字符
{
    if(n==1||n==2)
    {
        int i=k,j=0;
        for(;i<k+v;i++,j++)
        {
            ans[n][j]=b[n][i];
        }
        ans[n][j]='\0';
        return ans[n];
    }
    if(k<a[n-2])
    {
        if(k+v<=a[n-2])return find(n-2,k,v);
        else
        {
            strcpy(ans[n],find(n-2,k,a[n-2]-k));
            strcpy(ans[n-1],find(n-1,0,k-a[n-2]+v));
            strcat(ans[n],ans[n-1]);
            return ans[n];
        }
    }
    else return find(n-1,k-a[n-2],v);
}
int main()
{
    int T,n;
    LL k;
    init();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %lld",&n,&k);
        printf("%s\n",find(n,k-1,10));
    }
    return 0;
}
