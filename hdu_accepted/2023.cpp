#include<iostream>
using namespace std;
int main()
{
	int n,m;
	int score[50][5];
	double average[50];
	double subject[5];
	int tempn,tempm;
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
		{
			tempm=0;
			for(int j=0;j<m;j++)
			{
				cin>>score[i][j];
				tempm+=score[i][j];
			}
			average[i]=tempm/double(m);
		}
		for(int i=0;i<m;i++)
		{
			tempn=0;
			for(int j=0;j<n;j++)
			{
				tempn+=score[j][i];
			}
			subject[i]=tempn/double(n);
		}
		tempn=0;
		for(int i=0;i<n;i++)
		{
			tempm=0;
			for(int j=0;j<m;j++)
			{
				if(score[i][j]>=subject[j])tempm++;
			}
			if(tempm==m)tempn++;
		}
		for(int i=0;i<n-1;i++)printf("%.2lf ",average[i]);
		printf("%.2lf",average[n-1]);
		cout<<endl;
		for(int i=0;i<m-1;i++)printf("%.2lf ",subject[i]);
		printf("%.2lf",subject[m-1]);
		cout<<endl;
		cout<<tempn<<endl<<endl;
	}
	return 0;
} 
