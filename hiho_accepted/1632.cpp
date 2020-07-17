#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char ans[100][100];
int n;
void change()
{
    int i=0,j=0;
    char tap[10000];
    int tik=0;
    tap[tik]=ans[i][j];
    while(tik<n*n-1)
    {
        //向右走一步
        if(j<n-1&&ans[i][j+1]!='#')
        {
            j++;
            tik++;
            tap[tik]=ans[i][j];
            ans[i][j]='#';
        }
        //走到左下角
        while(j>0&&i<n-1&&ans[i+1][j-1]!='#')
        {
            i++,j--;
            tik++;
            tap[tik]=ans[i][j];
            ans[i][j]='#';
        }
        //向下走一步
        if(i<n-1&&ans[i+1][j]!='#')
        {
            i++;
            tik++;
            tap[tik]=ans[i][j];
            ans[i][j]='#';
        }
        //走到右上角
        while(i>0&&j<n-1&&ans[i-1][j+1]!='#')
        {
            i--,j++;
            tik++;
            tap[tik]=ans[i][j];
            ans[i][j]='#';
        }
    }
    i=0,j=0,tik=0;
    memset(ans,0,sizeof(ans));
    ans[i][j]=tap[tik];
    while(tik<n*n-1)
    {
        while(j<n-1&&ans[i][j+1]==0)//向右走
        {
            j++;
            tik++;
            ans[i][j]=tap[tik];
        }
        while(i<n-1&&ans[i+1][j]==0)//向下走
        {
            i++;
            tik++;
            ans[i][j]=tap[tik]; 
        }
        while(j>0&&ans[i][j-1]==0)//向左走
        {
            j--;
            tik++;
            ans[i][j]=tap[tik];
        }
        while(i>0&&ans[i-1][j]==0)//向上走
        {
            i--;
            tik++;
            ans[i][j]=tap[tik];
        }
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("\n%s",ans[i]);
        change();
        for(int i=0;i<n;i++)
            printf("%s\n",ans[i]);
    }
    return 0;
}
