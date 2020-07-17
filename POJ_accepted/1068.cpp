#include<iostream>
using namespace std;
int ans[21];
int main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        ans[0]=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>ans[i];
			int j=i-1;
			while(ans[i]-ans[j]<i-j)j--;
			if(i!=n)cout<<i-j<<' ';
			else cout<<i-j<<'\n';
        }
    }
    return 0;
}