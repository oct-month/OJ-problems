#include<iostream>
#include<string>
using namespace std;
int nex[100002];
bool bmp(string &a,string &b)//看一看b是否为a的子串
{
    int bl=b.size(),al=a.size(),k;
    nex[0]=0;
    for(int i=1;i<bl;i++)
    {
        k=nex[i-1];//取前一个字符的next值
        while(b[i]!=b[k]&&k>0)k=nex[k-1];//找到下一个与ans[i-1]相同的字符位
        if(b[i]==b[k])nex[i]=k+1;
        else nex[i]=0;
    }
    int i=0,j=0;
    while(i<al)
    {
        if(a[i]==b[j])
        {
            i++,j++;
            if(j==bl)return true;
        }
        else
        {
            if(j==0)i++;
            else j=nex[j-1];
        }
    }
    return false;
}
int main()
{
    string a,b;
    int al,bl,n;
    cin>>a;
    cin>>n;
    al=a.size();
    while(n--)
    {
        cin>>b;
        bl=b.size();
        if(al==bl)
        {
            if(a==b)printf("jntm!\n");
            else printf("friend!\n");
        }
        else if(al>bl)
        {
            if(bmp(a,b))printf("my child!\n");
            else printf("oh, child!\n");
        }
        else if(al<bl)
        {
            if(bmp(b,a))printf("my teacher!\n");
            else printf("senior!\n");
        }
    }
    return 0;
}

//第一次 kmp