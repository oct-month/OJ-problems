#include<iostream>
#include<cstring>
using namespace std;
int dp_box[100005];
int dp[100005];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int box_num,goods_num,money,box_weight,weight,value;
	while(cin>>box_num>>money)
	{
		memset(dp_box,0,sizeof(dp));
		while(box_num--)
		{
			cin>>box_weight>>goods_num;
			memcpy(dp,dp_box,sizeof(dp));//继承上一次的dp
			while(goods_num--)
			{
				cin>>weight>>value;//dp[i]存的是：到这一层子包花费i时（还没有付盒子钱）所能得到的最大价值
				for(int i=money-box_weight;i>=weight;i--)
					dp[i]=max(dp[i-weight]+value,dp[i]);//对子包进行dp
			}
			for(int i=money;i>=box_weight;i--)
				dp_box[i]=max(dp[i-box_weight],dp_box[i]);
		}//                          买           不买
		cout<<dp_box[money]<<endl;
	}
	return 0;
}