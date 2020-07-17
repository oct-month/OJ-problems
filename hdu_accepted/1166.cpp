#include<iostream>
#include<cstring>
using namespace std;
#define lowbit(i) (i&(-i))
int a[50001];
int detail[50001];
char action[10];
int N;
void update(int *array,int a,int e)
{
    while(a<=N)
    {
        array[a]+=e;
        a+=lowbit(a);//???
    }
}
int qsum(int *array,int h)//?h????
{
    int tap=0;
    while(h>=1)
    {
        tap+=array[h];
        h-=lowbit(h);
    }
    return tap;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&N);
        memset(detail,0,sizeof(detail));
        for(int i=1;i<=N;i++)
        {
            scanf("%d",a+i);
            a[i]+=a[i-1];
        }
        printf("Case %d:\n",t);
        while(1)
        {
            int i,j;
            scanf("%s",action);
            if(action[0]=='E')break;
            else scanf(" %d %d",&i,&j);
            if(action[0]=='A')
            {
                update(detail,i,j);
            }
            else if(action[0]=='S')
            {
                update(detail,i,-j);
            }
            else if(action[0]=='Q')
            {
                int tap=a[j]-a[i-1];
                tap+=qsum(detail,j)-qsum(detail,i-1);
                printf("%d\n",tap);
            }
            else break;
        }
    }
    return 0;
}