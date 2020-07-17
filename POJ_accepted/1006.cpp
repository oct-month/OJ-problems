#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    int cas=0;
    while(cin>>a>>b>>c>>d&&a!=-1)
    {
        a%=23;
        b%=28;
        c%=33;
        cas++;
        for(int i=0;i<=28*33;i++)
        {
            if((a+23*i-b)%28==0)
            {
                if((a+23*i-c)%33==0)
                {
                    d=a+23*i-d;
                    while(d<=0)d+=23*28*33;
                    break;
                }
            }
        }
        printf("Case %d: the next triple peak occurs in %d days.\n",cas,d);
    }
    return 0;
}