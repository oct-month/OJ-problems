#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char ans[16][26];
char cns[16][26];
int n;
void get(int a,int b)
{
    if(a>n)return;
    if(b>n)strcpy(ans[(a+1)/2],cns[a]);
    else 
    {
        strcpy(ans[(a+1)/2],cns[a]);
        strcpy(ans[n-b/2+1],cns[b]);
        get(a+2,b+2);
    }
}
int main()
{
    int cas=0;
    while(~scanf("%d",&n)&&n)
    {
        cas++;
        for(int i=1;i<=n;i++)
            scanf("%s",cns[i]);
        get(1,2);
        printf("SET %d\n",cas);
        for(int i=1;i<=n;i++)
            printf("%s\n",ans[i]);
    }
    return 0;
}
