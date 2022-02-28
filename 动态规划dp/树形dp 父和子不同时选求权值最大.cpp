/*
树形dp 相邻父和子不同时选求权值最大
http://acm.hdu.edu.cn/showproblem.php?pid=1520
每个点都有独立的权值，每相邻的父节点和子节点不可以同时选，求选出点的权值和最大值
*/
vector<int>v[6050];
int dp[6050][2],pre[6050],n,l,k;
void dfs(int id)
{
	for(int i=0;i<v[id].size();i++)
	dfs(v[id][i]);
	for(int i=0;i<v[id].size();i++){
		dp[id][0]+=max(dp[v[id][i]][0],dp[v[id][i]][1]);
		dp[id][1]+=dp[v[id][i]][0];
	}
}
void solve(){
	 while(cin>>n){
   		memset(dp,0,sizeof(dp));
   		memset(pre,-1,sizeof(pre));
   		for(int i=1;i<=n;i++){
   			cin>>dp[i][1];v[i].clear();
		}
   		while(cin>>l>>k){
   			if(l==0&&k==0)break;
			v[k].push_back(l);
			pre[l]=k;   	
		}
		int f=1;
		while(pre[f]!=-1)f=pre[f];
   		dfs(f);
   		cout<<max(dp[f][0],dp[f][1])<<endl;
   }
}