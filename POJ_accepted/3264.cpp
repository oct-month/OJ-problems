#include<iostream>
#include<cstdio>
using namespace std;
#define INTMAX 0x7fffffff
int max_cow,min_cow;
struct Cnode//线段树
{
    int start,end;
    int max,min;
    //Cnode*left,*right;
};
Cnode ans[420000];
void build(int root,int L,int R)//以1为根，L,R为左右区间
{
    ans[root].start=L;
    ans[root].end=R;
    ans[root].max=-INTMAX;
    ans[root].min=INTMAX;
    if(L!=R)
    {
        build(2*root,L,(L+R)/2);
        build(2*root+1,(L+R)/2+1,R);
    }
}
void insert(int root,int i,int e)
{
    if(ans[root].start==ans[root].end)
    {
        ans[root].min=ans[root].max=e;
        return;
    }
    ans[root].max=max(ans[root].max,e);
    ans[root].min=min(ans[root].min,e);
    if(i<=(ans[root].start+ans[root].end)/2)insert(root*2,i,e);//在左边
    else insert(root*2+1,i,e);//在右边
}
void query(int root,int L,int R)//查询L~R之间的最值
{
    if(L==ans[root].start&&R==ans[root].end)
    {
        max_cow=max(max_cow,ans[root].max);
        min_cow=min(min_cow,ans[root].min);
        return;
    }
    int tap=(ans[root].start+ans[root].end)/2;
    if(L>tap)//在右边
    {
        query(2*root+1,L,R);
    }
    else if(R<=tap)//在左边
    {
        query(2*root,L,R);
    }
    else//在中间
    {
        query(2*root,L,tap);
        query(2*root+1,tap+1,R);
    }
}
int main()
{
    int N,Q;
    while(~scanf("%d %d",&N,&Q))
    {
        build(1,1,N);
        int h;
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&h);
            insert(1,i,h);
        }
        while(Q--)
        {
            max_cow=-INTMAX;
            min_cow=INTMAX;
            int L,R;
            scanf("%d %d",&L,&R);
            query(1,L,R);
            printf("%d\n",max_cow-min_cow);
        }
    }
    return 0;
}