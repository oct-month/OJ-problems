#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
LL rule[525],goal[525];
struct node
{
    LL step;//第一次走到目标的步数
    LL cicle;//循环
}point[525];
LL ex_gcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    LL d=ex_gcd(b,a%b,x,y);
    LL temp=x;
    x=y,y=temp-a/b*y;
    return d;
}
LL china(LL n)
{
    LL a,b,c,x,y,d,lcm;
    for(LL i=2;i<=n;i++)
    {
        a=point[i-1].cicle;
        b=point[i].cicle;
        c=point[i].step-point[i-1].step;
        d=ex_gcd(a,b,x,y);
        lcm=a/d*b;
        if(c%d)return -1;
        x*=c/d;
        LL tap=b/d;
        x=(x%tap+tap)%tap;
        x=x*point[i-1].cicle+point[i-1].step;
        x=(x%lcm+lcm)%lcm;
        point[i].cicle=lcm;
        point[i].step=x;
    }
    return point[n].step;
}
int main()
{
    int n;
    bool visit[525];
    while(cin>>n&&n)
    {
        for(int i=1;i<=n;i++)cin>>rule[i];
        for(int i=1;i<=n;i++)cin>>goal[i];
        for(int i=1;i<=n;i++)
        {
            memset(visit,0,sizeof(visit));
            int p=i,step=0;
            while(!visit[p])
            {
                if(goal[i]==p)point[i].step=step;
                visit[p]=true;
                p=rule[p];
                step++;
            }
            point[i].cicle=step;
        }
        LL res=china(n);
        cout<<res<<endl;
    }
}
//先找到循环规律，发现每位的变化情况若是可以到达，则存在循环节，
//所以使得第i位成功转换的操作次数是若干个循环节后再操作几次，
//故可以使用不互质的中国剩余定理求解。