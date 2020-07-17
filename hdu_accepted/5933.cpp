#include<iostream>
using namespace std;
long long ans[100001];
int main()
{
    long long T,n,k,a,num;
    int x,y;
    cin>>T;
    long long tmp;
    for(long long u=1;u<=T;u++)
    {
        cin>>n>>k;
        tmp=0;
        num=0;
        ans[0]=0;
        x=0;
        y=0;
        for(long long i=0;i<n;i++)
        {
            scanf("%lld",&a);//cin超时
            ans[i+1]=ans[i]+a;
            tmp+=a;
        }
        if(tmp%k!=0)num=-1;
        else
        {
            tmp/=k;
            for(int i=1;i<n;i++)
            {
                if(ans[i]%tmp==0)x++;//已断开的点不用再断
                else y++;//需要合起来的点
            }
            num=k-1-x+y;
        }
        cout<<"Case #"<<u<<": "<<num<<endl;
    }
    return 0;
}