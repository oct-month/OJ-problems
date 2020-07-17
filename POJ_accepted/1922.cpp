#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define INTMAX 0xfffffff
struct ride
{
    int Vi;
    int Ti;
    int data;
};
ride rides[10001];
bool cmp(ride &a,ride &b)
{
    return a.data<b.data;
}
int main()
{
    int n;
    while(cin>>n&&n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>rides[i].Vi>>rides[i].Ti;
            rides[i].data=ceil(16200.0/rides[i].Vi+rides[i].Ti);
        }
        sort(rides+1,rides+n+1,cmp);
        int tmp;
        for(int i=1;i<=n;i++)
        {
            if(rides[i].Ti>=0){tmp=rides[i].data;break;}
        }
        cout<<tmp<<endl;
    }
    return 0;
}