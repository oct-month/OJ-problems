#include<iostream>
using namespace std;
int a[30]={0,2,6,20,72,72,56,60,12,92,56,0,52,12,56,40,92,32,56,80,32,52,56};
int main()
{
    long long T,n;
    while(scanf("%lld",&T)&&T)
    {
        for(long long u=1;u<=T;u++)
        {
            scanf("%lld",&n);
            printf("Case %lld: ",u);
            if(n<=22)printf("%d\n",a[n]);
            else printf("%d\n",a[(n-3)%20+3]);
        }
        printf("\n");
    }
    return 0;
}