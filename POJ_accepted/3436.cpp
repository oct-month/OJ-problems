#include<iostream>
#include<queue>
#include<cstring>
#include<set>
using namespace std;
#define INTMAX 0xfffffff
int p,N;//p????N???
struct node
{
	int Q;//??
	int inp[11];//?
	int oup[11];//?
};
node robt[51];
int map[110][110];//?????0????2N+1
int map_tap[110][110];//?????
struct no
{
	int node;
	int deth;//??
};
int depth[110];//? i ????
int fenc()
{
	memset(depth,-1,sizeof(depth));
	queue<no> Q;
	depth[0]=0;
	Q.push({0,0});
	while(!Q.empty())
	{
		no tap=Q.front();
		Q.pop();
		for(int i=1;i<=2*N+1;i++)
		{
			if(depth[i]==-1&&map[tap.node][i])
			{
				depth[i]=tap.deth+1;
				Q.push({i,tap.deth+1});
			}
		}
	}
	if(depth[2*N+1]!=-1)return 1;//?????
	return 0;
}
bool visit[110];
int sum;
int dinic()
{
	sum=0;
	deque<int> Q;
	int m=2*N+1;//m ???
	while(fenc())
	{
		Q.push_back(0);
		memset(visit,0,sizeof(visit));
		visit[0]=true;
		while(!Q.empty())
		{
			int nd=Q.back();
			if(nd==m)
			{
				int min_line=INTMAX;//???
				int min_vs;//??????
				for(int i=1;i<Q.size();i++)
				{
					int fron=Q[i-1],edn=Q[i];
					if(map[fron][edn]<min_line)
					{
						min_line=map[fron][edn];
						min_vs=fron;
					}
				}
				sum+=min_line;
				for(int i=1;i<Q.size();i++)
				{
					int fron=Q[i-1],edn=Q[i];
					map[fron][edn]-=min_line;
					map[edn][fron]+=min_line;//?????
				}
				while(Q.back()!=min_vs)//??
				{
					visit[Q.back()]=false;
					Q.pop_back();
				}
			}
			else
			{
				int i;
				for(i=0;i<=m;i++)
				{
					if(!visit[i]&&depth[nd]+1==depth[i]&&map[nd][i]>0)//??nd ???i?
					{
						visit[i]=true;
						Q.push_back(i);
						break;
					}
				}
				if(i>m)Q.pop_back();//?????
			}
		}
	}
}
bool judge(int a,int b)//?? a ????? b
{
	for(int i=1;i<=p;i++)
	{
		if(robt[b].inp[i]==2||robt[b].inp[i]==robt[a].oup[i]);
		else return false;
	}
	return true;
}
struct noo
{
	int fron;
	int edn;
	int v;
};
struct rule
{
	bool operator()(const noo &a,const noo &b)
	{
		if(a.fron==b.fron)return a.edn<b.edn;
		return a.fron<b.fron;
	}
};
int main()
{
	while(cin>>p>>N)
	{
		memset(map,0,sizeof(map));
		for(int i=1;i<=N;i++)
		{
			cin>>robt[i].Q;
			for(int j=1;j<=p;j++)cin>>robt[i].inp[j];
			for(int j=1;j<=p;j++)cin>>robt[i].oup[j];
		}
		for(int i=1;i<=p;i++)
		{
			robt[0].oup[i]=0;//0 ??????
			robt[N+1].inp[i]=1;//N+1 ??????
		}
		queue<noo> Qe;
		for(int i=1;i<=N;i++)
		{
			map[2*i-1][2*i]=robt[i].Q;//?????? 2 ??2*i-1 ? 2*i
			if(judge(0,i))map[0][2*i-1]=INTMAX;//?????? i
			if(judge(i,N+1))map[2*i][2*N+1]=INTMAX;//?? i ????
			for(int j=1;j<=N;j++)
			{
				if(judge(i,j))map[2*i][2*j-1]=INTMAX;//?????????
				if(i!=j)Qe.push({i,j,0});
			}
		}
		memcpy(map_tap,map,sizeof(map));//????
		//system("pause");
		dinic();
		//system("pause");
		multiset<noo,rule> fil;
		while(!Qe.empty())
		{
			noo tap=Qe.front();
			Qe.pop();
			int i=2*tap.fron,j=2*tap.edn-1;
			tap.v=map_tap[i][j]-map[i][j];
			if(tap.v>0)fil.insert(tap);
		}
		cout<<sum<<' '<<fil.size()<<endl;
		while(!fil.empty())
		{
			noo tap=*fil.begin();
			fil.erase(fil.begin());
			cout<<tap.fron<<' '<<tap.edn<<' '<<tap.v<<endl;
		}
	}
	return 0;
}
//https://www.cnblogs.com/wangyiming/p/6357709.html