/*
P1757 通天之分组背包 https://www.luogu.com.cn/problem/P1757
t[k][j] 表示第k组的第j件物品的编号是多少，再用cnt[k]表示第k组物品有多少个。
对每组的背包都进行一次0-1dp
*/

int a[1001],b[1001],g[1001][1001],cnt[1001],dp[1001];
void solve(){
	int n,m,max_cnt=0;cin>>m>>n; //背包容量，物品数目 
	for(int i=0;i<n;i++){
		int c;cin>>a[i]>>b[i]>>c;
		max_cnt=max(max_cnt,c); //记录共有几组
		cnt[c]++; //记录第C组共有几件物品
		g[c][cnt[c]]=i; //记录第C组第i件物品的的序号
	}
	for(int i=1;i<=max_cnt;i++){ //枚举max_cnt个组
		for(int j=m;j>=0;j--){  //枚举容量 
			for(int k=1;k<=cnt[i];k++){  //枚举各组物品的编号 
				if(j>=a[g[i][k]]) dp[j]=max(dp[j],dp[j-a[g[i][k]]]+b[g[i][k]]);
			}
		} 
	}
	cout<<dp[m];
} 