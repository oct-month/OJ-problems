#include<iostream>
#include<cstring>
using namespace std;
int mapp[101][101];
struct robo
{
    int x,y;
    int direct;
};
robo robot[101];
int main()
{
    int T,A,B,N,M;
    char e;
    int atap,btap;
    int flag;
    int f1,f2;
    cin>>T;
    while(T--)
    {
        flag=3;
        memset(mapp,0,sizeof(mapp));
        cin>>A>>B;
        cin>>N>>M;
        for(int i=1;i<=N;i++)
        {
            cin>>robot[i].x>>robot[i].y>>e;
            switch(e)
            {
                case 'N':robot[i].direct=0;break;
                case 'E':robot[i].direct=1;break;
                case 'S':robot[i].direct=2;break;
                case 'W':robot[i].direct=3;break;
            }
            mapp[robot[i].x][robot[i].y]=i;
        }
        for(int i=0;i<M;i++)
        {
            cin>>atap>>e>>btap;
            if(flag==3)
            {
                f1=atap;
                switch(e)
                {
                    case 'L':robot[atap].direct=(robot[atap].direct+4-btap%4)%4;break;
                    case 'R':robot[atap].direct=(robot[atap].direct+btap)%4;break;
                    case 'F':
                        if(robot[atap].direct==0)
                        {
                            while(btap--)
                            {
                                mapp[robot[atap].x][robot[atap].y]=0;
                                robot[atap].y++;
                                if(robot[atap].y>B){flag=1;break;}
                                if(mapp[robot[atap].x][robot[atap].y]){flag=2;f2=mapp[robot[atap].x][robot[atap].y];break;}
                                mapp[robot[atap].x][robot[atap].y]=atap;
                            } 
                        }
                        else if(robot[atap].direct==1)
                        {
                            while(btap--)
                            {
                                mapp[robot[atap].x][robot[atap].y]=0;
                                robot[atap].x++;
                                if(robot[atap].x>A){flag=1;break;}
                                if(mapp[robot[atap].x][robot[atap].y]){flag=2;f2=mapp[robot[atap].x][robot[atap].y];break;}
                                mapp[robot[atap].x][robot[atap].y]=atap;
                            } 
                        }
                        else if(robot[atap].direct==2)
                        {
                            while(btap--)
                            {
                                mapp[robot[atap].x][robot[atap].y]=0;
                                robot[atap].y--;
                                if(robot[atap].y<=0){flag=1;break;}
                                if(mapp[robot[atap].x][robot[atap].y]){flag=2;f2=mapp[robot[atap].x][robot[atap].y];break;}
                                mapp[robot[atap].x][robot[atap].y]=atap;
                            } 
                        }
                        else
                        {
                            while(btap--)
                            {
                                mapp[robot[atap].x][robot[atap].y]=0;
                                robot[atap].x--;
                                if(robot[atap].x<=0){flag=1;break;}
                                if(mapp[robot[atap].x][robot[atap].y]){flag=2;f2=mapp[robot[atap].x][robot[atap].y];break;}
                                mapp[robot[atap].x][robot[atap].y]=atap;
                            } 
                        }
                        break;
                }
            }
        }
        if(flag==1)cout<<"Robot "<<f1<<" crashes into the wall"<<endl;
        else if(flag==2)cout<<"Robot "<<f1<<" crashes into robot "<<f2<<endl;
        else cout<<"OK"<<endl;
    }
    return 0;
}

