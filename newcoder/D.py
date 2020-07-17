def exgcd(a,b):
    """扩展欧几里得"""
    if b==0:
        return (a,1,0)
    d,x,y=exgcd(b,a%b)
    tmp=x
    x=y
    y=tmp-a//b*y;
    return (d,x,y)
 
n,m=map(int,input().split())    #读取一行
 
a,b=map(int,input().split())
ans1,ans2=a,b
for i in range(n-1):
    a,b=map(int,input().split())
    c=b-ans2
    d,x,y=exgcd(ans1,a)
    if c%d!=0:
        print("he was definitely lying")
        exit(0)
    x*=c//d
    t=a//d
    x=(x%t+t)%t
    tap=ans1
    ans1=ans1*a//d
    ans2=x*tap+ans2
    ans2%=ans1

if ans2>m:
    print("he was probably lying")
else:
    print(int(ans2))

#https://ac.nowcoder.com/acm/contest/890/D