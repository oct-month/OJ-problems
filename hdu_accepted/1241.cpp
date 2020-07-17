#include<iostream>
using namespace std;
char ans[100][100];
int m,n;
int t1,t2;
int find()
{
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(ans[i][j]=='@')
            {
                t1=i;
                t2=j;
                return 1;
            }
    return 0;
}
void color(int a,int b)//遍历连在一起的格，并染色
{
    if(a<0||a>=m||b<0||b>=n)return;
    if(ans[a][b]=='@')
    {
        ans[a][b]='*';
        color(a,b+1);
        color(a,b-1);
        color(a+1,b);
        color(a+1,b-1);
        color(a+1,b+1);
        color(a-1,b);
        color(a-1,b-1);
        color(a-1,b+1);
    }
}
int main()
{
    int num;
    while(cin>>m>>n&&m&&n)
    {
        num=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                cin>>ans[i][j];
        while(find())
        {
            color(t1,t2);
            num++;
        }
        cout<<num<<endl;
    }
    return 0;
}