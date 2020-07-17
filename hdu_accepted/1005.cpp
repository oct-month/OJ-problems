#include<iostream>
using namespace std;
long long A,B;
long long f(long long n)
{
	if(n==1||n==2)return 1;
	return (A*f(n-1)+B*f(n-2))%7;
}
int main()
{
	long long n;
	while(cin>>A>>B>>n)
	{
		if(A==0&&B==0&&n==0)break;
		n%=48;
		cout<<f(n)<<endl;
	}
	return 0;
}
