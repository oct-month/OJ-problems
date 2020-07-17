#include<iostream>
#include<string>
#include<cstring>
#include<stack>
using namespace std;
struct
{
    string name;
    int dead;
    int cost;
}obj[16];
struct
{
    int score;
    int father;
    int time;
    int objnum;
}dp[1<<15];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        memset(dp,0,sizeof(dp));
        cin>>N;
        for(int i=1;i<=N;i++)
            cin>>obj[i].name>>obj[i].dead>>obj[i].cost;
        for(int i=1;i<(1<<N);i++)
        {
            dp[i].score=0xfffffff;
            for(int j=N;j>=1;j--)
            {
                if(i&(1<<(j-1)))//如果第j门课被做
                {
                    int temp=i-(1<<(j-1));//temp表示不考虑第j门课（未被做）的情况
                    int t=dp[temp].time+obj[j].cost-obj[j].dead;
                    if(t<0)t=0;//在截止时间内完成
                    if(dp[temp].score+t<dp[i].score)
                    {
                        dp[i].score=dp[temp].score+t;
                        dp[i].father=temp;//记录上一次的状态
                        dp[i].time=dp[temp].time+obj[j].cost;
                        dp[i].objnum=j;//记录当前写的哪门
                    }
                }
            }
        }
        printf("%d\n",dp[(1<<N)-1].score);
        stack<int> S;
        int tap=(1<<N)-1;
        for(int i=0;i<N;i++)
        {
            S.push(dp[tap].objnum);
            tap=dp[tap].father;
        }
        for(int i=0;i<N;i++)
        {
            tap=S.top();
            S.pop();
            cout<<obj[tap].name<<endl;
        }
    }
    return 0;
}