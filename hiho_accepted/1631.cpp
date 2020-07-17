#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,x,p,q;
int c[101];
bool visit[101];
int main()
{
    while(~scanf("%d %d %d",&m,&n,&x))//m条鱼,n只猫,x分钟
    {
        for(int i=1;i<=n;i++)scanf("%d",c+i);
        sort(c+1,c+n+1);
        p=m;
        q=0;
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i%c[j]==0)
                {
                    if(c[j]==1&&p)p--,q++,visit[j]=true;//1的时候特判
                    if(visit[j])visit[j]=false,q--;//猫变为空闲，未吃完的鱼少一条
                }
                else if(!visit[j]&&p)
                {
                    p--;
                    q++;
                    visit[j]=true;
                }
            }
        }
        printf("%d %d\n",p,q);
    }
    return 0;
}
