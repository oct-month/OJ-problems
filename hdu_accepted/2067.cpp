#include<iostream>
#include<cstring>
using namespace std;
long long a[36][36];
int main()
{
    long long cas=0;
    int n;
    while(cin>>n&&n!=-1)
    {
        cas++;
        memset(a,0,sizeof(a));
        a[1][1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                if(i==j)a[i][j]=a[i-1][j-1]+a[i][j-1];
                else a[i][j]=a[i-1][j]+a[i][j-1];
            }
        }
        cout<<cas<<' '<<n<<' '<<2*a[n][n]<<endl;
    }
    return 0;
}