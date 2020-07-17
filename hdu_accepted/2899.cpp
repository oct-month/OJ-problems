#include<iostream>
using namespace std;
double sum(double a,double b)//计算a的b次方
{
    double tap=1;
    while(b--)tap*=a;
    return tap;
}
double F1(double a)
{
    double rap;
    rap=42*sum(a,6)+48*sum(a,5)+21*sum(a,2)+10*a;
    return rap;
}
double F(double a,double Y)
{
    double rap;
    rap=6*sum(a,7)+8*sum(a,6)+7*sum(a,3)+5*sum(a,2)-Y*a;
    return rap;
}
double find(double a,double b,double Y)//在a和b中找零点
{
    if(F1(a)-Y==0)return a;
    int i=200;
    while(i--)
    {
        if(F1((a+b)/2)-Y<0)a=(a+b)/2;
        else if(F1((a+b)/2)-Y>0)b=(a+b)/2;
    }
    return (a+b)/2;
}
int main()
{
    int T;
    double Y;
    cin>>T;
    while(T--)
    {
        cin>>Y;
        double x;
        for(x=0;x<=100;x++)
        {
            if(F1(x)-Y>0)break;
        }
        if(x!=0) x=find(x-1,x,Y);
        printf("%.4lf\n",F(x,Y));
    }
    return 0;
}