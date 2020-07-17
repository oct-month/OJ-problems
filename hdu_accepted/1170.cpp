#include<iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	char x;
	int a,b;
	while(T--)
	{
		cin>>x>>a>>b;
		if(x=='+')cout<<a+b<<endl;
		else if(x=='-')cout<<a-b<<endl;
		else if(x=='*')cout<<a*b<<endl;
		else 
		{
			if(a%b==0)cout<<a/b<<endl;
			else printf("%.2f\n",a/(1.0*b));
		}
	}
	return 0;
} 
