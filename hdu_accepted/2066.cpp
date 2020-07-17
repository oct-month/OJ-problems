#include<iostream>
using namespace std;
#define INTMAX 0x7ffffff
int city[1001][1001];
int Dcity[1001];
int main()
{
    int T,S,D,Scity,citynum;
    while(cin>>T>>S>>D)
    {
        citynum=0;
        for(int i=0;i<1001;i++)
            for(int j=0;j<1001;j++)
                city[i][j]=INTMAX;
        int a,b,time;
        for(int i=0;i<T;i++)
        {
            cin>>a>>b>>time;
            if(a>citynum)citynum=a;
            if(b>citynum)citynum=b;
            if(city[a][b]>time)city[b][a]=city[a][b]=time;
        }
        int De[1001];//从0到其他点的距离
        for(int i=0;i<=citynum;i++)
        {
            De[i]=INTMAX;
        }
        for(int i=0;i<S;i++)
        {
            cin>>Scity;//0到该点的距离设为0
            city[Scity][0]=city[0][Scity]=0;
            De[Scity]=0;
            for(int j=1;j<=citynum;j++)
                if(De[j]>city[Scity][j])De[j]=city[Scity][j];
        }
        for(int i=0;i<D;i++)cin>>Dcity[i];
        for(int i=1;i<=citynum;i++)
            for(int j=1;j<=citynum;j++)
                if(De[i]+city[i][j]<De[j])De[j]=De[i]+city[i][j];
        for(int i=1;i<=citynum;i++)
            for(int j=1;j<=citynum;j++)
                if(De[j]+city[j][i]<De[i])De[i]=De[j]+city[j][i];
        int hl=INTMAX,h;
        for(int i=0;i<D;i++)
        {
            h=Dcity[i];
            if(De[h]<hl)
            {
                hl=De[h];
            }
        }
        cout<<hl<<endl;
    }
    return 0;
}
//把0看作最开始的点，0到题中所给的起点设置距离为0，就变成了单源最短路了，也就不用多次Dijkstra了