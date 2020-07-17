#include<iostream>
using namespace std;
int main()
{
    int x,y;
    while(cin>>x>>y&&(x||y))
    {
        int e=x;
        for(int i=1;i<y;i++)
        {
            x*=e;
            x=x%1000;
        }
        cout<<x<<endl;
    }
    return 0;
}