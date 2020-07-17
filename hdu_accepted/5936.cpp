#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL a[10][100000];
LL b[10][100000];
LL cif(LL a,LL k)
{
    LL e=1;
    while(k--)e*=a;
    return e;
}
LL f(LL y,LL k)
{
    LL e=0;
    while(y)
    {
        e+=cif(y%10,k);
        y/=10;
    }
    return e;
}
int main()
{
    for(LL i=1;i<10;i++)
        for(LL j=0;j<100000;j++)
        {
            a[i][j]=f(j,i)-j*100000;
            b[i][j]=f(j,i)-j;
        }
    for(LL i=1;i<10;i++)
    {
        sort(a[i],a[i]+100000);
        sort(b[i],b[i]+100000);
    }
    LL T,ynum,x,k;
    cin>>T;
    for(LL u=1;u<=T;u++)
    {
        scanf("%lld%lld",&x,&k);
        ynum=0;
        bool flag=false;
        LL low,up,mid;
        for(LL i=0;i<100000;i++)
        {
			if(a[k][i]+b[k][99999]<x)continue;
            low=0;
            up=100000;
            while(low<=up)
            {
                mid=(low+up)/2;
                if(a[k][i]+b[k][mid]==x)//找到一个值，向四周查探
                {
                    low=up=mid;
                    while(low>=0&&a[k][i]+b[k][low]==x)low--;
                    low++;
                    while(up<=99999&&a[k][i]+b[k][up]==x)up++;
                    mid=up-low;
                    flag=true;
                    break;
                }
                else if(a[k][i]+b[k][mid]<x)low=mid+1;
                else up=mid-1;
            }
            if(flag)ynum+=mid;
            flag=false;
        }
		if(x==0)ynum--;//y!=0
        printf("Case #%lld: %lld\n",u,ynum);
    }
    return 0;
}
/*的位数不会超过10位，因为如果超过十位的话f(y, k)-y一定是个负数
比如假设y是11位，那么f(y, k)最大值是9^9*11它只有10位
这样可以将y强行填到10位，比如y=236，那么就让y=0000000236
这样就不用判断位数了
之后暴力出前5位的所有情况(0-99999)
举个例子：假设当时是25436，k为6，那么当前值就是2^6+5^6+4^6+3^6+6^6-25436*100000
将算出来的100000个值存到a[k][]数组里排个序，注意每个k都要这样算一次
然后再暴力算出后5位的所有情况(0-99999)
和上面一样的：假设当时是25436，k为6，那么当前值就是2^6+5^6+4^6+3^6+6^6-25436
将算出来的100000个值存到b[k][]数组里排个序，每个k都要这样算一次仍然
每次询问x, k相当于找到有多少组a[k][]+b[k][]==x，因为R和L都是有序，这样就可以O(n)计算了
注意当x=0时答案要-1，因为y!=0
 */