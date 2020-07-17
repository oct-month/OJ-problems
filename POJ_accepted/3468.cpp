#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
LL ans[100005];
LL n,m;
LL C[100005];
LL detail[100005];
LL sum_detail[100005];
#define lowbit(i) (i&(-i))
void update(LL *array,LL a,LL b)
{
    while(a<=n)
    {
        array[a]+=b;
        a+=lowbit(a);//找父节点
    }
}
LL qsum(LL *array,LL i)
{
    LL tap=0;
    while(i>=1)
    {
        tap+=array[i];
        i-=lowbit(i);
    }
    return tap;
}
int main()
{
    while(~scanf("%lld %lld",&n,&m))
    {
        memset(sum_detail,0,sizeof(sum_detail));
        memset(detail,0,sizeof(detail));
        ans[0]=0;
        for(LL i=1;i<=n;i++)
        {
            //cin>>ans[i];
            scanf("%lld",ans+i);
            //update(C,i,ans[i]);
            ans[i]+=ans[i-1];
        }
        char e;
        LL a,b,d;
        while(m--)
        {
            //cin>>e;
            scanf("\n%c",&e);
            if(e=='Q')
            {
                //cin>>a>>b;
                scanf(" %lld %lld",&a,&b);
                LL tap=ans[b]-ans[a-1];
                tap+=(b+1)*qsum(detail,b)-qsum(sum_detail,b);
                tap-=a*qsum(detail,a-1)-qsum(sum_detail,a-1);
                printf("%lld\n",tap);
            }
            else
            {
                //cin>>a>>b>>d;
                scanf(" %lld %lld %lld",&a,&b,&d);
                update(detail,a,d);
                update(detail,b+1,-d);
                update(sum_detail,a,a*d);
                update(sum_detail,b+1,-(b+1)*d);
            }
        }
    }
    //system("pause");
    return 0;
}