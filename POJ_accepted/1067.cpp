#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		int tap;
		if(a>b)
		{
			tap=b;
			b=a;
			a=tap;
		}
		double k=(double)b-a;
        int term=(int)(k*(1+sqrt(5))/2);
        if(term==a)
            printf("0\n");
        else
            printf("1\n");
	}
	return 0;
}
