#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool ans[10001];
int seque(int e)
{
    int tap=e;
    while(e)
    {
        tap+=e%10;
        e/=10;
    }
    return tap;
}
int main()
{
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=10000;i++)
    {
        if(!ans[i])
        {
            int tap=i;
            while(tap<=10000)
            {
                tap=seque(tap);
                ans[tap]=1;
            }
        }
    }
    for(int i=1;i<=10000;i++)
        if(!ans[i])printf("%d\n",i);
    return 0;
}