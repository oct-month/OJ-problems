#include<iostream>
#include<map>
#include<string> 
using namespace std;
struct word
{
	string first;
	int second;
};
int main()
{
	map<string,int> M;
	map<string,int>::iterator I;
	int n;
	string N;
	word wd;
	while(cin>>n)
	{
		if(n==0)break;
		for(int i=0;i<n;i++)
		{
			cin>>N;
			M[N]++;
		}
		wd.second=-1;
		for(I=M.begin();I!=M.end();I++)
		{
			if(I->second>wd.second)
			{
				wd.second=I->second;
				wd.first=I->first;
			}
		}
		M.clear();
		cout<<wd.first<<endl;
	}
	return 0;
} 
