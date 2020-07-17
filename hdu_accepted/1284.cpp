#include <iostream>
#include<cstring>
using namespace std;
typedef long long LL;
LL dp[32770];
int main()
{
    int n;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;//用于更新dp[1]
    for( int i=1; i<=3; i++ )//从只有1分硬币开始
    {
        for( int j=i; j<=32769; j++ )
            dp[j] = dp[j] + dp[j-i];
    }
    while( scanf("%d", &n) != EOF )
    {
        printf("%d\n", dp[n]);
    }
    return 0;
}