#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int T,a[4];
    double z,s;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        scanf("%d%d%d%d",a,a+1,a+2,a+3);
        sort(a,a+4);
        if(a[3]>=a[0]+a[1]+a[2])printf("Case %d: -1\n",i);
        else
        {
            z=(a[0]+a[1]+a[2]+a[3])/2.0;//泰勒公式
            s=sqrt((z-a[0])*(z-a[1])*(z-a[2])*(z-a[3]));
            printf("Case %d: %.6lf\n",i,s);
        }
    }
    return 0;
}