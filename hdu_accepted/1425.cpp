#include<cstdio>
#include<algorithm>
using namespace std;
int s[1000005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,m,i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
    	for(i=0;i<n;i++)scanf("%d",&s[i]);
    	sort(s,s+n,cmp);
    	for(i=0;i<m;i++)
    	{
    		if(i==m-1)printf("%d\n",s[i]);
    	    else printf("%d ",s[i]);
    	}
    }
	return 0;
}
