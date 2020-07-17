#include<iostream>
using namespace std;
char ans[32];
int C[32][32];
void init()
{
    for(int i=1;i<=31;i++)C[0][i]=0;
    for(int i=0;i<=31;i++)C[i][0]=1;
    for(int i=1;i<=31;i++)
        for(int j=1;j<=31;j++)
            C[i][j]=C[i-1][j]+C[i-1][j-1];
}
int main()
{
    init();
    int T,n,m,k;
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k;
        ans[0]='1';
        k=C[n-1][m-1]-k+1;//转换为求第 k大
        int tap=0;
        m-=1;
        for(int i=1;i<n;i++)
        {
            tap+=C[n-i-1][m-1];//第i+1位放 1
            if(tap<k)ans[i]='0';
            else 
            {
                if(m>0)ans[i]='1';
                else ans[i]='0';
                tap-=C[n-i-1][m-1];
                m--;
            }
        }
        ans[n]='\0';
        cout<<ans<<endl;
    }
    return 0;
}
//题目：https://ac.nowcoder.com/acm/contest/897/J